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
  // Find the largest number, k
  int max = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  // Create histogram with k range
  int *histogram = calloc(max + 1, sizeof(int));
  for (int i = 0; i < size; i++) {
    histogram[arr[i]]++;
  }

  // Create running sum position array
  for (int i = 0; i < max + 1; i++) {
    // if it's the first element, just add the number directly,
    // otherwise add the previous value as well
    histogram[i] = i != 0 ? histogram[i - 1] + histogram[i] : histogram[i];
  }

  // Starting from end of input array, assign elements to new output array
  int *outputArray = calloc(size, sizeof(int));

  for (int i = size - 1; i >= 0; i--) {
    // to get the position of the current index of the input array, we refer to;
    // the running sum - 1
    outputArray[histogram[arr[i]]-- - 1] = arr[i];
    // minus 1 since it doesn't account the 0th index
  }

  // Copy the sorted output to the original array
  memcpy(arr, outputArray, sizeof(int) * size);
}