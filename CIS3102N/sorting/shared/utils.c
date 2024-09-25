#include <stdio.h>
#define SIZE 5

void printArray(int *, int);

void printArray(int arr[], int len) {
  printf("[");
  for (int i = 0; i < len; i++) {
    i < len - 1 ? printf("%d, ", arr[i]) : printf("%d", arr[i]);
  }
  printf("]\n");
}

int arr[] = {3, 2, 1, 0, -1};