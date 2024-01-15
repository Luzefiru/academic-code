package Activity10_de_Jesus;

public class MultipleInheritance {
  public static void main(String[] args) {
    ChristmasTree tree = new ChristmasTree();
    tree.illuminate();
    tree.decorate("lights, balls, and a star at the top");
    tree.illuminate();
  }

  public static interface Decorable {
    public void decorate(String decorations);
  }

  public static interface Illuminatable {
    public void illuminate();
  }

  public static class ChristmasTree implements Decorable, Illuminatable {
    String decorations;

    public ChristmasTree() {
      this.decorations = "nothing";
      System.out.println("Placed up a new Christmas Tree! Please decorate it.");
    }

    public void decorate(String decorations) {
      this.decorations = decorations;
    }

    public void illuminate() {
      System.out.println("The tree is illuminated! It is decorated with: " + this.decorations + ".");
    }
  }
}
