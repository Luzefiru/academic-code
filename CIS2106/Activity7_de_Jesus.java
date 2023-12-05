import java.util.Scanner;
import java.util.ArrayList;

public class Activity7_deJesus {

    public static void main(String[] args) {
        System.out.println("[Printing even numbers until 20]");
        printEvenNumbers(20);
        System.out.println("[Factorial of 4]");
        printFactorial(4);
        System.out.println("[Displaying array {1,2,3} with forEach]");
        int[] arr = {1, 2, 3};
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
    }

    public static void displayArray(ArrayList<Integer> L) {
        L.forEach(e -> {
            System.out.println(e);
        });
    }
}
