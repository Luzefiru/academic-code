#include "shared/utils.c"

void sort(int arr[], int size);

int main(void) {
  sort(arr, SIZE);
  printArray(arr, SIZE);

  return 0;
}

void sort(int arr[], int size) {
  int i, j, gap, toInsert;
  for (gap = size / 2; gap > 0; gap /= 2) {

    // i and j represent the offset (gap) multiplier
    for (i = 1; i * gap < size; i++) {
      toInsert = arr[i * gap];

      for (j = i; j > 0 && arr[(j - 1) * gap] > toInsert; j--) {
        arr[j * gap] = arr[(j - 1) * gap];
      }
      arr[j * gap] = toInsert;
    }
  }
}

// notice that it is identical to insertion sort, just with offsets
void insertion(int arr[], int size) {
  int i, j, toInsert;

  for (i = 1; i < size; i++) {
    toInsert = arr[i];
    for (j = i; j > 0 && arr[j - 1] > toInsert; j--) {
      arr[j] = arr[j - 1];
    }
    arr[j] = toInsert;
  }
}