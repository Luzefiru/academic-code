using Microsoft.EntityFrameworkCore;
using Npgsql;
using server.Models;
using Microsoft.AspNetCore.Mvc;

var builder = WebApplication.CreateBuilder(args);



// Add services to the container.
// Learn more about configuring Swagger/OpenAPI at https://aka.ms/aspnetcore/swashbuckle
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();
// Database
var connectionString = "Host=localhost;Username=postgres;Password=example;Database=postgres";
builder.Services.AddDbContext<BlogDbContext>(opt => opt.UseNpgsql(connectionString));
builder.Services.AddDbContext<UserDbContext>(opt => opt.UseNpgsql(connectionString));
builder.Services.AddDatabaseDeveloperPageExceptionFilter();
// CORS service
builder.Services.AddCors(options =>
{
    options.AddDefaultPolicy(builder =>
    {
        builder.AllowAnyOrigin()
               .AllowAnyMethod()
               .AllowAnyHeader();
    });
});

var app = builder.Build();

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

app.UseCors();
app.UseHttpsRedirection();

// Main Application
// User & Auth Endpoints
app.MapPost("/user/login", async (string UserName, string Password, UserDbContext db) =>
{
    Console.WriteLine("Hello");
    var user = await db.Users.FirstOrDefaultAsync(u => u.UserName == UserName && u.Password == Password);

    if (user != null)
    {
        return Results.Ok(user);
    }
    else
    {
        return Results.Unauthorized();
    }
});

app.MapGet("/user/{id}", async (int id, UserDbContext db) =>
    await db.Users.FindAsync(id)
            is User user
                ? Results.Ok(user)
                : Results.NotFound());

// Blog Posts endpoints
app.MapGet("/blogs", async (BlogDbContext db) =>
    await db.Blogs.ToListAsync());

app.MapGet("/blogs/{id}", async (int id, BlogDbContext db) =>
    await db.Blogs.FindAsync(id)
        is Blog blog
            ? Results.Ok(blog)
            : Results.NotFound());

// User Actions endpoints
app.MapPost("/blogs", async (User user, string Title, string Content, BlogDbContext db) =>
{
    // Check if the user has writer or admin role
    if (user.Role != UserRole.Writer && user.Role != UserRole.Admin)
    {
        return Results.Unauthorized();
    }

    // Data Validation for blog post
    if (Title.Length == 0 || Content.Length == 0)
    {
        return Results.StatusCode(400);
    }

    var newBlog = new Blog
    {
        Title = Title,
        Content = Content,
        Likes = 0,
        AuthorId = user.Id,
        DatePosted = DateTime.Now.ToUniversalTime(),
    };

    db.Blogs.Add(newBlog);
    await db.SaveChangesAsync();

    return Results.Created($"/blogs/{newBlog.Id}", newBlog);
});

app.MapDelete("/blogs/{id}", async (int id, [FromQuery] int userId, BlogDbContext blogDb, UserDbContext userDb) =>
{
    if (await blogDb.Blogs.FindAsync(id) is Blog blog && await userDb.Users.FindAsync(userId) is User user)
    {
        if (blog.AuthorId != user.Id && user.Role != UserRole.Admin)
        {
            return Results.Unauthorized();
        }

        blogDb.Blogs.Remove(blog);
        await blogDb.SaveChangesAsync();
        return Results.NoContent();
    }

    return Results.NotFound();
});

app.MapPut("/blogs/{id}", async (int id, User user, string Title, string Content, BlogDbContext db) =>
{
    // Check if the user has writer or admin role
    if (user.Role != UserRole.Writer && user.Role != UserRole.Admin)
    {
        return Results.Unauthorized();
    }

    var blog = await db.Blogs.FindAsync(id);

    if (blog == null)
    {
        return Results.NotFound();
    }

    // Check if the user is the author of the blog post
    if (blog.AuthorId != user.Id)
    {
        return Results.Unauthorized();
    }

    blog.Title = Title;
    blog.Content = Content;

    await db.SaveChangesAsync();

    return Results.Ok(blog);
});

app.MapPost("/blogs/{id}/like", async (int id, User user, BlogDbContext db) =>
{
    Console.WriteLine("Hello");

    // Check if the user has any available role
    if (user.Role != UserRole.Guest && user.Role != UserRole.Writer && user.Role != UserRole.Admin)
    {
        return Results.Unauthorized();
    }
    // Check if the blog post exists
    var blog = await db.Blogs.FindAsync(id);
    if (blog == null)
    {
        // If the blog post does not exist, return a 404 Not Found
        return Results.NotFound($"Blog post with id {id} not found");
    }
    blog.Likes++;
    blog.DatePosted = blog.DatePosted.ToUniversalTime();
    db.Blogs.Update(blog);
    await db.SaveChangesAsync();
    return Results.Ok(blog);
});

app.Run();
