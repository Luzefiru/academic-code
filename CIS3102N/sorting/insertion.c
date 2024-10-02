#include "shared/utils.c"

void sort(int arr[], int size);

int main(void) {
  sort(arr, SIZE);
  printArray(arr, SIZE);

  return 0;
}

void sort(int arr[], int size) {
  int i, j, toInsert;

  for (i = 1; i < size; i++) {
    toInsert = arr[i];
    for (j = i; j > 0 && arr[j - 1] > toInsert; j--) {
      arr[j] = arr[j - 1];
    }
    arr[j] = toInsert;
  }
}