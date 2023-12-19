using Microsoft.EntityFrameworkCore;

namespace server.Models
{
  public class BlogDbContext : DbContext
  {
    public BlogDbContext(DbContextOptions<BlogDbContext> options)
        : base(options)
    {
    }

    public DbSet<Blog> Blogs { get; set; } // Use plural form for DbSet property name
  }
}