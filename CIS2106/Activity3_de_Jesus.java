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
