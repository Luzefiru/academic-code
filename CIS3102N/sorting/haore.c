#include "shared/utils.c"

void quickSort(int *, int, int);

int main(void) {
  int array[5] = {5, 4, 3, 2, 1};
  int size = 5;
  quickSort(array, 0, size - 1);
  printArray(array, size);

  return 0;
}

void quickSort(int arr[], int low, int high) {
  // we only do this is low index is lower than high index
  if (low < high) {
    int pivot = arr[low];
    int x = low - 1;
    int y = high + 1;

    // while x < y (they do not cross)
    while (1) {
      // starting from left, we find arr[x] > pivot
      do {
        x++;
      } while (arr[x] < pivot);
      // starting from right, we find arr[y] < pivot
      do {
        y--;
      } while (arr[y] > pivot);

      // if the points meet or they cross, stop
      if (x >= y)
        break;

      // we swap the elements across paritions to be in order with pivot
      int tmp = arr[x];
      arr[x] = arr[y];
      arr[y] = tmp;
    }

    // we quicksort the partition before y (inclusive)
    quickSort(arr, low, y);
    // we quicksort the partition after y (exclusive)
    quickSort(arr, y + 1, high);
  }
}