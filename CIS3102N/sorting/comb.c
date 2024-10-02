#include "shared/utils.c"

void sort(int arr[], int size);

int main(void) {
  sort(arr, SIZE);
  printArray(arr, SIZE);

  return 0;
}

void sort(int arr[], int size) {
  int gap, i;

  // it's Bubble Sort, but we compare elements with a gap
  for (gap = size / 1.3; gap > 0; gap /= 1.3) {
    // the condition is that we cannot let the right element go beyond the size
    for (i = 0; i + gap < size; i++) {
      if (arr[i] > arr[i + gap]) {
        int tmp = arr[i];
        arr[i] = arr[i + gap];
        arr[i + gap] = tmp;
      }
    }
  }
}