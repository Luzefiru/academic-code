package Activity10_de_Jesus;

public class SingleLevel {
  public static void main(String args[]) {
    Christmas ball = new Christmas("Ball");
    System.out.println(ball);
    ChristmasTree tree = new ChristmasTree("Merry Christmas from the de Jesus Family!");
    System.out.println(tree);
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
}
