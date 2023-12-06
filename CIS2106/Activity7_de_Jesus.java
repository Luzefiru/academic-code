// 1. Write a program that uses a for loop to print the even numbers from 1 to 20.
// 2. Create a program that uses a while loop to calculate the factorial of a given number.
// 3. Develop a program that prompts the user to enter a password and keeps asking until the correct password ("openSesame") is entered.
// 4. Write a program that uses the enhanced for loop to iterate through an array of integers and prints each element.

import java.util.Scanner;
import java.util.ArrayList;

public class Activity7_de_Jesus {
    public static void main(String[] args) {
        System.out.println("[Printing even numbers until 20]");
        printEvenNumbers(20);
        System.out.println("[Factorial of 4]");
        printFactorial(4);
        System.out.println("[Displaying array {1,2,3} with forEach]");
        int[] arr = { 1, 2, 3 };
        ArrayList<Integer> L = new ArrayList<>();

        for (int i : arr) {
            L.add(i);
        }

        displayArray(L);
        System.out.println("[openSesame]");
        askForPassword();
    }

    public static void printEvenNumbers(int max) {
        for (int i = 1; i <= max; i++) {
            if (i % 2 == 0) {
                System.out.println(i);
            }
        }
    }

    public static void printFactorial(int num) {
        int prod = 1;
        while (num != 0) {
            prod *= num;
            num--;
        }
        System.out.println(prod);
    }

    public static void askForPassword() {
        Scanner get = new Scanner(System.in);
        boolean isRoss = false;
        while (!isRoss) {
            System.out.print("Enter the correct password: ");
            isRoss = get.nextLine().equals("openSesame");
        }
        get.close();
    }

    public static void displayArray(ArrayList<Integer> L) {
        L.forEach(e -> {
            System.out.println(e);
        });
    }
}
