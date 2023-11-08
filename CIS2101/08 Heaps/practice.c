#include <stdio.h>
#include <stdlib.h>

#define MAX 10

/*
A Complete Binary Tree that is a Partially-Ordered Tree where
  - all levels are filled except the last one
  - insertion happens at the next available node, from the left
  - a child is always greater than its parent
  - deleting the smallest deletes the root node
*/ 
typedef struct Heap {
  int node[MAX];
  int lastIndex;
} *Heap;

/**
 * @brief Inserts `value` into a Heap `h`, in its partially-ordered position.
 * 
 * Pseudocode (if not full):
 * 1. Insert at the index after the previous `lastIndex`
 * 2. While the current node is not the root (`node[0]`) AND parent node value is lesser than the current node's value:
 *   2.a. Swap the current value with the parent if it's lesser
 *   2.b. Move `currentIndex` traversal variable to the parent's index
 * 3. Increment lastIndex
 * 
 * @param h a Complete Binary Tree that is Partially-ordered
 * @param value the value to be inserted
 */
void insert(Heap h, int value) {
  int currentIndex = h->lastIndex + 1; // Start at the next available node
  h->node[currentIndex] = value; // Inserting

  while (currentIndex != 0 && h->node[(currentIndex-1) / 2] > h->node[currentIndex]) {
    // Swap the current node's value with its parent node
    int tmp = h->node[currentIndex];
    h->node[currentIndex] = h->node[(currentIndex-1) / 2];
    h->node[(currentIndex-1) / 2] = tmp;
    
    // Change current index to parent
    currentIndex = (currentIndex - 1) / 2;
  }

  h->lastIndex++;
}

/**
 * @brief 
 * 
 * @param h 
 * @return int 
 */
int deleteMin(Heap h);


Heap init(void);
void displayHeapHelper(Heap h, int index, int level);
void displayHeap(Heap h);

int main(void) {
  Heap heap = init();
  insert(heap, 6);
  insert(heap, 5);
  insert(heap, 4);
  insert(heap, 3);
  displayHeap(heap);
}

/**
 * @brief Creates an empty heap, with `lastIndex` set to `-1`
 * 
 * @return Heap 
 */
Heap init(void) {
  Heap newHeap = malloc(sizeof(struct Heap));
  newHeap->lastIndex = -1;
}

/**
 * @brief Helper to display the heap as a tree-like structure.
 * 
 * @param h the Heap to be displayed
 * @param index the index of the current node
 * @param level the current level of the heap
 */
void displayHeapHelper(Heap h, int index, int level) {
    if (index <= h->lastIndex) {
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
    displayHeapHelper(h, 0, 0);
}