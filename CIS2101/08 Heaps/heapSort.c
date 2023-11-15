#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void heapSort(int *arr, int size);
void simpleHeapSort(int *arr, int size);
void displayArray(int *arr, int size);
void heapify(int *maxHeap, int size, int index);

int main(void) {
  int arr[MAX] = {5,2,4,1,6,7,9,21,69};
  displayArray(arr, MAX - 1);
  simpleHeapSort(arr, MAX - 1);
}

/**
 * @brief Turns an array into a max heap before sorting it in ascending order.
 * 
 * @param arr 
 * @param size 
 */
void heapSort(int *arr, int size) {
  int *maxHeap = malloc(sizeof(int) * size);
  int heapLastIndex = -1;

  // insert all values of the array into a max heap - O(log n), where n is the number of elements to insert
  for (int i = 0; i < size; i++) {
    maxHeap[heapLastIndex + 1] = arr[i]; // insert at the next last index
    heapLastIndex++;
    for (
      int currentIndex = heapLastIndex; // start at the inserted node index
      currentIndex > 0 && maxHeap[(currentIndex - 1) / 2] < maxHeap[currentIndex]; // if not root && parent is lesser than current node
      currentIndex = (currentIndex - 1) / 2 // move to the parent
      ) {
      // swap lesser parent with current node
      int tmp = maxHeap[currentIndex];
      maxHeap[currentIndex] = maxHeap[(currentIndex - 1) / 2];
      maxHeap[(currentIndex - 1) / 2] = tmp;
    }
  }

  // swap every largest (first element) to the last index then heapify while decrementing last index
  // O(n log n)
  for (int i = 0; i < size; i++) {
    int tmp = maxHeap[0];
    maxHeap[0] = maxHeap[heapLastIndex];
    maxHeap[heapLastIndex--] = tmp;
    heapify(maxHeap, heapLastIndex, 0);
  }
  
  displayArray(maxHeap, size);
}

void simpleHeapSort(int *arr, int size) {
  int lastIndex = size - 1;
  
  // starting from the last parent node, heapify subtrees until the root
  for (int i = (lastIndex - 1) / 2; i >= 0; i--) {
    heapify(arr, lastIndex, i);
  }

  // deleteMax every element from the max heap-like array
  for (int i = 0; i < size; i ++) {
    // swap max element at root with the last index
    int tmp = arr[0];
    arr[0] = arr[lastIndex];
    arr[lastIndex--] = tmp;
    // heapify from the root node
    heapify(arr, lastIndex, 0); 
  }

  displayArray(arr, size);
}

/**
 * @brief Heapify helper for a max heap;
 */
void heapify(int *maxHeap, int lastIndex, int index) {
  int largest = index;
  int leftChild = index * 2 + 1;
  int rightChild = index * 2 + 2;

  if (leftChild <= lastIndex && maxHeap[leftChild] > maxHeap[largest]) {
    largest = leftChild;
  }

  if (rightChild <= lastIndex && maxHeap[rightChild] > maxHeap[largest]) {
    largest = rightChild;
  }

  if (largest != index) {
    int tmp = maxHeap[index];
    maxHeap[index] = maxHeap[largest];
    maxHeap[largest] = tmp;
    heapify(maxHeap, lastIndex, largest);
  }
}

/**
 * @brief Helper to display the array for debugging.
 */
void displayArray(int *arr, int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
    (i < size-1) ? printf("%d, ", arr[i]) : printf("%d", arr[i]);
  }
  printf("]\n");
}