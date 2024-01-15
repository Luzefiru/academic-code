package Activity10_de_Jesus;

public class MultiLevel {
  public static void main(String args[]) {
    Christmas ball = new Christmas("This is a ball.");
    System.out.println(ball);
    ChristmasTree tree = new ChristmasTree("Merry Christmas from the de Jesus Family!");
    System.out.println(tree);
    DecoratedChristmasTree decoratedTree = new DecoratedChristmasTree("Happy New Year!", "Balls, Star, Branches");
    System.out.println(decoratedTree);
  }

  public static class Christmas {
    String information;

    public Christmas(String info) {
      this.information = info;
    }

    public String getInformation() {
      return this.information;
    }

    @Override
    public String toString() {
      return String.format("Information: %s\n", this.information);
    }
  }

  public static class ChristmasTree extends Christmas {
    String greeting;

    public ChristmasTree(String greeting) {
      super("This is a Christmas tree.");
      this.greeting = greeting;
    }

    @Override
    public String toString() {
      return super.toString() + String.format("Greeting: %s\n", this.greeting);
    }
  }

  public static class DecoratedChristmasTree extends ChristmasTree {
    String decorations;

    public DecoratedChristmasTree(String greeting, String deco) {
      super(greeting);
      this.decorations = deco;
    }

    @Override
    public String toString() {
      return super.toString() + String.format("Decorations: %s\n", this.decorations);
    }
  }
}
