#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct heap {
  int node[MAX];
  int size;
} *Heap;

void initHeap(Heap *h);
void displayHeapHelper(Heap h, int index, int level);
void displayHeap(Heap h);
void insert(Heap h, int newElem);
void heapify(Heap h, int i);
void heapSort(Heap h);

int main(void) {
  Heap H = &(struct heap){{9, 8, 7, 6, 5, 4, 3, 2, 1, 0}, 10};
  displayHeap(H);
  heapSort(H);
  displayHeap(H);
}

void initHeap(Heap *h) {
  *h = (Heap)malloc(sizeof(struct heap));
  (*h)->size = 0;
}

void insert(Heap h, int newElem) {
  int current;
  for (current = h->size;
       current > 0 && h->node[(current - 1) / 2] < h->node[current];
       current = (current - 1) / 2) {
    int tmp = h->node[current];
    h->node[current] = h->node[(current - 1) / 2];
    h->node[(current - 1) / 2] = tmp;
  }
  h->size++;
}

void heapify(Heap h, int i) {
  int largest = i;
  int LC = i * 2 + 1;
  int RC = i * 2 + 2;

  if (LC < h->size - 1 && h->node[LC] > h->node[largest]) {
    largest = LC;
  }

  if (RC < h->size - 1 && h->node[RC] > h->node[largest]) {
    largest = RC;
  }

  if (largest != i) {
    int tmp = h->node[i];
    h->node[i] = h->node[largest];
    h->node[largest] = tmp;
    heapify(h, largest);
  }
}

void heapSort(Heap h) {
  int trav;
  for (trav = (h->size - 2) / 2; trav >= 0; trav--) {
    heapify(h, trav);
  }

  int originalSize = h->size;
  for (trav = 0; trav < originalSize; trav++) {
    int tmp = h->node[0];
    h->node[0] = h->node[h->size - 1];
    h->node[h->size - 1] = tmp;
    h->size--;
    heapify(h, 0);
  }

  h->size = originalSize;
}

/**
 * @brief Helper to display the heap as a tree-like structure.
 *
 * @param h the Heap to be displayed
 * @param index the index of the current node
 * @param level the current level of the heap
 */
void displayHeapHelper(Heap h, int index, int level) {
  if (index <= h->size - 1) {
    displayHeapHelper(h, 2 * index + 2, level + 1);
    for (int i = 0; i < level; i++) {
      printf("    "); // for spacing
    }
    printf("%d\n", h->node[index]);
    displayHeapHelper(h, 2 * index + 1, level + 1);
  }
}

/**
 * @brief Displays the Heap as a tree structure.
 *
 * @param h the Heap to be displayed
 */
void displayHeap(Heap h) {
  puts("Heap:");
  printf("[ ");
  for (int i = 0; i < h->size; i++) {
    printf("%d ", h->node[i]);
  }
  printf("]");
  puts("\n");
  displayHeapHelper(h, 0, 0);
  puts("");
}