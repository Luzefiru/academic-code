using Microsoft.EntityFrameworkCore;

namespace server.Models
{
  public class UserDbContext : DbContext
  {
    public UserDbContext(DbContextOptions<UserDbContext> options) : base(options)
    {
    }

    public DbSet<User> Users { get; set; } // Represents the Users table in the database

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
      // Configure your entity properties and relationships here if needed
      modelBuilder.Entity<User>().ToTable("Users"); // Optionally specify a table name if required
    }
  }
}