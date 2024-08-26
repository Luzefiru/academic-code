#include <stdio.h>
#define LEN 5

void printArray(int *, int);

int main(void) {

  int arr[] = {3, 2, 1, 0, -1};

  int i = 1;
  while (i < LEN) {
    if (i != 0 && arr[i] < arr[i - 1]) {
      int tmp = arr[i];
      arr[i] = arr[i - 1];
      arr[i - 1] = tmp;
      i--;
    } else {
      i++;
    }
  }

  printArray(arr, LEN);

  return 0;
}

void printArray(int arr[], int len) {
  printf("[");
  for (int i = 0; i < len; i++) {
    i < len - 1 ? printf("%d, ", arr[i]) : printf("%d", arr[i]);
  }
  printf("]\n");
}