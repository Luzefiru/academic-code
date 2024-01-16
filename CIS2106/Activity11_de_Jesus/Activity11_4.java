package Activity11_de_Jesus;

public class Activity11_4 {
  public static void main(String[] args) {
    Coffee macchiato = new Coffee("Strawberry Macchiato");
    try {
      macchiato.serve();
    } catch (Error e) {
      System.out.println(e.getMessage());
    }

    macchiato.prepare();
    macchiato.serve();

    Tea greenTea = new Tea("O cha");
    greenTea.prepare();
    greenTea.serve();

    Smoothie mango = new Smoothie("Mango Shake");
    mango.prepare();
    mango.serve();
  }

  public static abstract class Beverage {
    String name;
    Boolean isReadyToServe;

    public Beverage(String name) {
      this.name = name;
      this.isReadyToServe = false;
    }

    public void prepare() {
      System.out.println(String.format("Preparaing %s...", this.name));
      System.out.println(String.format("Successfully prepared %s!", this.name));
      this.isReadyToServe = true;
    }

    public void serve() {
      if (!isReadyToServe) {
        throw new Error("ERR: Drink it not prepared yet! Please pepare it before serving.");
      }

      System.out.println(String.format("Successfully served %s!", this.name));
    }
  }

  public static class Coffee extends Beverage {
    public Coffee(String type) {
      super(String.format("Coffee (%s)", type));
    }
  }

  public static class Tea extends Beverage {
    public Tea(String type) {
      super(String.format("Tea (%s)", type));
    }
  }

  public static class Smoothie extends Beverage {
    public Smoothie(String type) {
      super(String.format("Smoothie (%s)", type));
    }
  }
}
