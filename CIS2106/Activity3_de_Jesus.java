// Declare 3 variables area, length and width of type double.
// Assign values to length and width to represent the dimensions of the rectangle (you can use any positive numbers).
// Calculate the area of the rectangle using the formula area = length * width.
// Display the calculated area on the screen.

// Rectangle Dimensions:
// Length: 5.5
// Width: 3.2
// Area: 17.6

// Your task is to implement this program using variables to store the dimensions and the calculated area of the rectangle. 

public class Activity3_de_Jesus {
  public static void main(String args[]) {
    double length = 5.5;
    double width = 3.2;
    double area = calculateAreaOfRectangle(length, width);

    System.out.println("Rectangle Dimensions:");
    System.out.println("Length: " + length);
    System.out.println("Width: " + width);
    System.out.println("Area: " + area);
  }

  public static double calculateAreaOfRectangle(double length, double width) {
    return length * width;
  }
}
