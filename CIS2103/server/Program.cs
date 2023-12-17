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


var app = builder.Build();

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

app.UseHttpsRedirection();

// Main Application
// User & Auth Endpoints
app.MapPost("/auth/login", async (string UserName, string Password, UserDbContext db) =>
{
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

app.MapDelete("/blogs/{id}", async (int id, [FromBody] User user, BlogDbContext db) =>
{
    if (await db.Blogs.FindAsync(id) is Blog blog)
    {
        if (blog.AuthorId != user.Id)
        {
            return Results.Unauthorized();
        }

        db.Blogs.Remove(blog);
        await db.SaveChangesAsync();
        return Results.NoContent();
    }

    return Results.NotFound();
});

app.MapPost("/blogs/{id}/like", async (int id, User user, BlogDbContext db) =>
{
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

    // Return success or appropriate response
    return Results.Ok(blog);
});

app.Run();
