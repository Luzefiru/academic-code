package Activity11_de_Jesus;

import java.util.ArrayList;

public class Activity11_5 {
  public static void main(String[] args) {
    ElectronicsCart eCart = new ElectronicsCart();
    GroceryCart gCart = new GroceryCart();

    eCart.addItem(new Item("Banana", 12.5, "Grocery"));
    gCart.addItem(new Item("Banana", 12.5, "Grocery"));
    eCart.addItem(new Item("iPhone 15 Pro Max", 49999.9, "Electronics"));

    System.out.println();
    System.out.println("Total cost of Grocery Cart is: " + gCart.calculateTotal() + " php.");
    System.out.println("Total cost of Electronics Cart is: " + eCart.calculateTotal() + " php.");
  }

  public static class Item {
    String name, category;
    Double price;

    public Item(String name, Double price, String category) {
      this.category = category;
      this.name = name;
      this.price = price;
    }

    public String getName() {
      return this.name;
    }

    public Double getPrice() {
      return this.price;
    }
  }

  public static interface ShoppingCart {
    Boolean addItem(Item itemToAdd);

    Double calculateTotal();
  }

  public static class GroceryCart implements ShoppingCart {
    private ArrayList<Item> cartItems;

    public GroceryCart() {
      this.cartItems = new ArrayList<>();
    }

    public Boolean addItem(Item itemToAdd) {
      if (!itemToAdd.category.toLowerCase().equals("grocery")) {
        System.out.println("ERR: Cannot add " + itemToAdd.getName() + " to grocery cart.");
        return false;
      }

      cartItems.add(itemToAdd);
      System.out.println("Successfully added " + itemToAdd.getName() + " to grocery cart.");
      return true;
    }

    public Double calculateTotal() {
      Double totalCost = 0.0;

      for (Item item : cartItems) {
        totalCost += item.getPrice();
      }

      return totalCost;
    }
  }

  public static class ElectronicsCart implements ShoppingCart {
    private ArrayList<Item> cartItems;

    public ElectronicsCart() {
      this.cartItems = new ArrayList<>();
    }

    public Boolean addItem(Item itemToAdd) {
      if (!itemToAdd.category.toLowerCase().equals("electronics")) {
        System.out.println("Cannot add " + itemToAdd.getName() + " to electronics cart.");
        return false;
      }

      cartItems.add(itemToAdd);
      System.out.println("Successfully added " + itemToAdd.getName() + " to electronics cart.");
      return true;
    }

    public Double calculateTotal() {
      Double totalCost = 0.0;

      for (Item item : cartItems) {
        totalCost += item.getPrice();
      }

      return totalCost;
    }
  }
}
