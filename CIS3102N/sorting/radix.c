#include "shared/utils.c"
#include <stdlib.h>
#include <string.h>

void sort(int arr[], int size);
void countingSort(int arr[], int size, int exp);

int main(void) {
  sort(arr, SIZE);
  printArray(arr, SIZE);

  return 0;
}

void sort(int arr[], int size) {
  int max = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  for (int exp = 1; max / exp > 0; exp *= 10) {
    countingSort(arr, size, exp);
  }
}

void countingSort(int arr[], int size, int exp) {
  // Create histogram of numbers of the input array
  int *histogram = calloc(10, sizeof(int));
  for (int i = 0; i < size; i++) {
    int digit = (arr[i] / exp) % 10;
    histogram[digit]++;
  }

  // Make prefix sum array
  for (int i = 1; i < 10; i++) {
    histogram[i] = histogram[i] + histogram[i - 1];
  }

  // Assign to output array, starting from the input array's end via prefix sum
  int *outputArray = calloc(size, sizeof(int));
  for (int i = size - 1; i >= 0; i--) {
    int digit = (arr[i] / exp) % 10;
    outputArray[histogram[digit]-- - 1] = arr[i];
  }

  memcpy(arr, outputArray, sizeof(int) * size);
}