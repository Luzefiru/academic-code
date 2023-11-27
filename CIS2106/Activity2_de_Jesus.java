// Declare variables for the following information about a person:  and 
// Use the three types of variables: local, instance and static
// Initialize each variable with appropriate values to represent the information of a person.
// Display the person's information on the screen using the variables.

public class Activity2_de_Jesus {
  public static String name = "Christian de Jesus"; // static variable
  public static void main(String[] args) {
    int age = 20; // instance variable
    printPersonalInformation(name, age);
  }

  public static void printPersonalInformation(String name, int age) {
    String gender = "Male"; // local variable

    System.out.println("Personal Information:");
    System.out.println("Name: " + name);
    System.out.println("Age: " + age);
    System.out.println("Gender: " + gender);
  }
}
