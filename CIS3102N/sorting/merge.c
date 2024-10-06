#include "shared/utils.c"
#include <stdlib.h>
#include <string.h>

void mergeSort(int arr[], int size);
void merge(int leftArray[], int leftSize, int rightArray[], int rightSize,
           int array[]);

int main(void) {
  mergeSort(arr, SIZE);
  printArray(arr, SIZE);

  return 0;
}

void mergeSort(int arr[], int size) {
  if (size <= 1) {
    return;
  }

  int middle = size / 2;

  // dynamically allocate memory for the left and right subarrays
  int *leftArray = malloc(sizeof(int) * middle);
  int *rightArray = malloc(sizeof(int) * (size - middle));

  // copy the left & right sides of the array
  memcpy(leftArray, arr, sizeof(int) * middle);
  memcpy(rightArray, arr + middle, sizeof(int) * (size - middle));

  // recursively break down into smaller subarrays
  mergeSort(leftArray, middle);
  mergeSort(rightArray, size - middle);

  // merge the sorted subarrays back into the original array
  merge(leftArray, middle, rightArray, size - middle, arr);

  // free subarrays since we merged it back to the original already
  free(leftArray);
  free(rightArray);
}

void merge(int leftArray[], int leftSize, int rightArray[], int rightSize,
           int arr[]) {
  // to keep track of the leftArray, rightArray, and array - respectively
  int i = 0, j = 0, k = 0;

  // while we still have elements on the left & right arrays
  while (i < leftSize && j < rightSize) {
    // we put the smallest element from either array into our original array
    if (leftArray[i] < rightArray[j]) {
      arr[k++] = leftArray[i++];
    } else {
      arr[k++] = rightArray[j++];
    }
  }

  // we add back the rest of the elements starting from the left array
  while (i < leftSize) {
    arr[k++] = leftArray[i++];
  }

  while (j < rightSize) {
    arr[k++] = rightArray[i++];
  }
}
