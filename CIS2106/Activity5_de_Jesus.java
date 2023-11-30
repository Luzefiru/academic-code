// Write a Java program that performs the following operations on two given numbers:
// Adds the two numbers.
// Subtracts the second number from the first number.
// Multiplies the two numbers.
// Divides the first number by the second number.
// You can use the following two numbers for your program: 
// int num1 = 10;
// int num2 = 5;
// Implement the program using appropriate variables and operators. Display the results of each operation on the screen.

// Example Output
// Number 1: 10
// Number 2: 5
// Result of addition: 10 + 5 = 15
// Result of subtraction: 10 - 5 = 5
// Result of multiplication: 10 * 5 = 50
// Result of division: 10 / 5 = 2

public class Activity5_de_Jesus {
  public static void main(String args[]) {
    int num1 = 10;
    int num2 = 5;

    System.out.println("Number 1: " + num1);
    System.out.println("Number 2: " + num2);

    System.out.println(String.format("Result of addition: %d + %d = %d", num1, num2, num1 + num2));
    System.out.println(String.format("Result of subtraction: %d - %d = %d", num1, num2, num1 - num2));
    System.out.println(String.format("Result of multiplication: %d * %d = %d", num1, num2, num1 * num2));
    System.out.println(String.format("Result of division: %d / %d = %d", num1, num2, num1 / num2));
  }
}
