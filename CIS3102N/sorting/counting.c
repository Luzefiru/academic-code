#include "shared/utils.c"
#include <stdlib.h>
#include <string.h>

void sort(int *, int);

int main(void) {
  sort(arr, SIZE);
  printArray(arr, SIZE);

  return 0;
}

void sort(int arr[], int size) {
  // Get the max value, which will determine the range of the histogram
  int max = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  // Create histogram of numbers of the input array
  int *histogram = calloc(max + 1, sizeof(int));
  for (int i = 0; i < size; i++) {
    histogram[arr[i]]++;
  }

  // Make prefix sum array
  for (int i = 1; i < max + 1; i++) {
    histogram[i] = histogram[i] + histogram[i - 1];
  }

  // Assign to output array, starting from the input array's end via prefix sum
  int *outputArray = calloc(size, sizeof(int));
  for (int i = size - 1; i >= 0; i--) {
    outputArray[histogram[arr[i]]-- - 1] = arr[i];
  }

  memcpy(arr, outputArray, sizeof(int) * size);
}