using Microsoft.EntityFrameworkCore;
using Npgsql;
using server.Models;

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


app.Run();
