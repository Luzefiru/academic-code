#include "shared/utils.c"

void sort(int arr[], int size);

int main(void) {
  sort(arr, SIZE);
  printArray(arr, SIZE);

  return 0;
}

void sort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int smallestIdx = i;
    for (int j = size - 1; j > i; j--) {
      if (arr[j] < arr[smallestIdx]) {
        smallestIdx = j;
      }
    }
    int tmp = arr[i];
    arr[i] = arr[smallestIdx];
    arr[smallestIdx] = tmp;
  }
}