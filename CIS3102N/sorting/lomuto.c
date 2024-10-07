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
    // we assign the last element of the partition as the pivot
    int pivot = arr[high];
    // our partitionIndex should be -1 of the low
    int partitionIndex = low - 1;

    // from low until high
    for (int i = low; i < high; i++) {
      // if the current element is less than or equal to the pivot
      if (arr[i] <= pivot) {
        // move the partitionIndex & swap it with the current element
        partitionIndex++;
        int tmp = arr[i];
        arr[i] = arr[partitionIndex];
        arr[partitionIndex] = tmp;
      }
    }

    // we swap our pivot to its proper spot
    // (all elements from low to partitionIndex are lower than it)
    int tmp = arr[partitionIndex + 1];
    arr[partitionIndex + 1] = arr[high];
    arr[high] = tmp;

    // we quicksort the left & right partitions
    quickSort(arr, low, partitionIndex);
    quickSort(arr, partitionIndex + 2, high);
  }
}