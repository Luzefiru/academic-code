#include "shared/utils.c"

void sort(int arr[], int size);
void heapify(int *maxHeap, int lastIndex, int index);

int main(void) {
  sort(arr, SIZE);
  printArray(arr, SIZE);

  return 0;
}

void sort(int *arr, int size) {
  int lastIndex = size - 1;

  for (int i = size / 2; i >= 0; i--) {
    heapify(arr, lastIndex, i);
  }

  for (int i = 0; i < size; i++) {
    int tmp = arr[0];
    arr[0] = arr[lastIndex];
    arr[lastIndex] = tmp;
    lastIndex--;
    heapify(arr, lastIndex, 0);
  }
}

void heapify(int arr[], int lastIndex, int index) {
  int largest = index;
  int left = index * 2 + 1;
  int right = index * 2 + 2;

  if (left <= lastIndex && arr[left] > arr[largest]) {
    largest = left;
  }
  if (right <= lastIndex && arr[right] > arr[largest]) {
    largest = right;
  }

  if (index != largest) {
    int tmp = arr[largest];
    arr[largest] = arr[index];
    arr[index] = tmp;
    heapify(arr, lastIndex, largest);
  }
}