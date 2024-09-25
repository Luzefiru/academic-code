#include "shared/utils.c"

void sort(int arr[], int size);

int main(void) {
  sort(arr, SIZE);
  printArray(arr, SIZE);

  return 0;
}

void sort(int arr[], int size) {
  int i, j;
  for (i = 1; i < size; i++) {
    // get ready to insert last element of search area
    int toInsert = arr[i];

    // while you are not at the first index & the next number is not sorted
    for (j = i; j > 0 && arr[j - 1] > toInsert; j--) {
      // keep shifting elements to the current index
      arr[j] = arr[j - 1];
    }

    // we stop at either; arr[0] or when the next element is sorted relative to
    // the element toInsert
    arr[j] = toInsert;
  }
}