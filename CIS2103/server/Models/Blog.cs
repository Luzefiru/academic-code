namespace server.Models
{
  public class Blog
  {
    public int Id { get; set; }
    public string? Title { get; set; }
    public string? Content { get; set; }
    public int Likes { get; set; }

    public int AuthorId { get; set; }
    public User? Author { get; set; }

    public DateTime DatePosted { get; set; }
  }
}
