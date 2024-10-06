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

  int *leftArray = calloc(middle, sizeof(int));
  int *rightArray = calloc(size - middle, sizeof(int));

  memcpy(leftArray, arr, sizeof(int) * middle);
  memcpy(rightArray, arr + middle, sizeof(int) * (size - middle));

  mergeSort(leftArray, middle);
  mergeSort(rightArray, size - middle);

  merge(leftArray, middle, rightArray, size - middle, arr);

  free(leftArray);
  free(rightArray);
}

void merge(int leftArray[], int leftSize, int rightArray[], int rightSize,
           int arr[]) {
  int i = 0, j = 0, k = 0;

  while (i < leftSize && j < rightSize) {
    if (leftArray[i] < rightArray[j]) {
      arr[k++] = leftArray[i++];
    } else {
      arr[k++] = rightArray[j++];
    }
  }

  while (i < leftSize) {
    arr[k++] = leftArray[i++];
  }

  while (j < rightSize) {
    arr[k++] = rightArray[j++];
  }
}