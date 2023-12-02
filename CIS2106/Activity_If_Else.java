import java.util.Scanner;

public class If_Else {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("What is your age? ");
    int age = scanner.nextInt();
    scanner.close();

    if (age >= 60) {
      System.out.println("Senior Citizen");
    } else if (age >= 20) {
      System.out.println("Adult");
    } else if (age >= 13) {
      System.out.println("Teenager");
    } else if (age >= 0) {
      System.out.println("Child");
    }
  }
}