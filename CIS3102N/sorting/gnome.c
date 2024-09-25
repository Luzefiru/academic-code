#include "shared/utils.c"

void gnomeSort(int *, int);

int main(void) {
  gnomeSort(arr, SIZE);
  printArray(arr, SIZE);

  return 0;
}

void gnomeSort(int arr[], int size) {
  int i = 1, tmp;
  while (i < SIZE) {
    if (i == 0 || arr[i] > arr[i - 1]) {
      i++;
    } else {
      int tmp = arr[i];
      arr[i] = arr[i - 1];
      arr[i - 1] = tmp;
      i--;
    }
  }
}