package Activity10_de_Jesus;

public class Hierarchal {
  public static void main(String[] args) {
    SantaClaus santa = new SantaClaus();
    Reindeer rudolph = new Reindeer("Rudolph");
    Reindeer dasher = new Reindeer("Dasher");
    Reindeer blitzen = new Reindeer("Blitzen");

    santa.greet();
    rudolph.illuminate();
    dasher.illuminate();
    blitzen.illuminate();
  }

  public static class Christmas {
    String greeting;

    public Christmas(String greeting) {
      this.greeting = greeting;
    }

    public void greet() {
      System.out.println(greeting);
    }
  }

  public static class SantaClaus extends Christmas {
    public SantaClaus() {
      super("Ho ho ho! Merry Christmas!");
    }

    public void giveGift(String name) {
      System.out.println("Santa gave a gift to: " + name);
    }
  }

  public static class Reindeer extends Christmas {
    String name;

    public Reindeer(String name) {
      super("In a one-horse open sleigh!");
      this.name = name;
    }

    public void illuminate() {
      System.out.println(String.format("%s illuminated the sky!", this.name));
    }
  }
}
