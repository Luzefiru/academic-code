namespace server.Models
{
  public enum UserRole
  {
    Guest, // 0
    Writer, // 1
    Admin // 2
  }
  public class User
  {
    public int Id { get; set; }
    public string? UserName { get; set; }
    public string? Password { get; set; }
    public UserRole Role { get; set; }
  }
}