public class Activity9_de_Jesus {
  public static void main(String[] args) {
    int[] nums1 = { 1, 2, 3, 4, 5 };
    System.err.println(String.format("Given: int[] nums = {1, 2, 3, 4, 5}; sum = %d", sum(nums1)));
    int[] nums2 = { 51, 12, 35, 42, 50 };
    System.err.println(String.format("Given: int[] nums = {51, 12, 35, 42, 50}; max = %d", max(nums2)));
    int[][] nums3 = { { 1, 10 }, { 99, 12 }, { 3, 2 }, { 4, 7, 51 }, { 5, 45, 50 } };
    System.err.println(
        String.format("Given: int[][] nums = {{1,10}, {99,12}, {3,2}, {4,7,51}, {5,45,50}}; max = %d", sum2d(nums3)));
    System.err.println(
        String.format("Given: int[][] nums = {{1,10}, {99,12}, {3,2}, {4,7,51}, {5,45,50}}; find2d: 50 = %s",
            find2d(nums3, 50) ? "true" : "false"));
    System.err.println(
        String.format("Given: int[][] nums = {{1,10}, {99,12}, {3,2}, {4,7,51}, {5,45,50}}; find2d: 123 = %s",
            find2d(nums3, 500) ? "true" : "false"));
  }

  // Write a function that calculates the sum of all elements in a
  // single-dimensional array.
  public static int sum(int[] arr) {
    int sum = 0;
    for (int i = 0; i < arr.length; i++) {
      sum += arr[i];
    }

    return sum;
  }

  // Create a function to find the maximum value in a single-dimensional array.
  public static int max(int[] arr) {
    int max = arr[0];
    for (int i = 1; i < arr.length; i++) {
      max = arr[i] > max ? arr[i] : max;
    }
    return max;
  }

  // Write a function to compute the sum of all elements in a two-dimensional
  // array.
  public static int sum2d(int[][] arr) {
    int sum = 0;
    for (int i = 0; i < arr.length; i++) {
      for (int j = 0; j < arr[i].length; j++)
        sum += arr[i][j];
    }

    return sum;
  }

  // Create a function to find a specific element in a two-dimensional array.
  public static boolean find2d(int[][] arr, int target) {
    for (int i = 0; i < arr.length; i++) {
      for (int j = 0; j < arr[i].length; j++)
        if (arr[i][j] == target) {
          return true;
        }
    }

    return false;
  }
}
