package Activity10_de_Jesus;

public class Hybrid {
  public static void main(String[] args) {
    ChristmasTree tree = new ChristmasTree();
    tree.illuminate();
    tree.decorate("vibrant lights & decorations");
    System.out.println();
    tree.illuminate();
  }

  public static interface Decorable {
    public void decorate(String decorations);
  }

  public static interface Illuminatable {
    public void illuminate();
  }

  public static class Christmas {
    String greeting, details;

    public Christmas(String greeting, String details) {
      this.greeting = greeting;
      this.details = details;
    }
  }

  public static class ChristmasTree extends Christmas implements Decorable, Illuminatable {
    String decorations;

    public ChristmasTree() {
      super("Merry Christmas and a Happy New Year!", "I am a Christmas Tree.");
      this.decorations = "nothing";
    }

    public void decorate(String decorations) {
      this.decorations = decorations;
    }

    public void illuminate() {
      System.out.println("You illuminated the Christmas Tree! It is decorated with: " + this.decorations + ".");
      System.out.println(this.greeting);
      System.out.println(this.details);
    }
  }
}
