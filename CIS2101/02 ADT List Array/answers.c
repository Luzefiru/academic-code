#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef enum {TRUE, FALSE} Boolean;

typedef struct {
  char Elem[SIZE];
  int count;
} List;

void initializeListA(List *L);
List initializeListB(void);
void displayList(List L);
int findElem(List L, char target);
void insertFirst(List *L, char newElem);
void deleteElem(List *L, char targetElem);

int main(void) {
  // 1.a
  List ListA;
  initializeListA(&ListA);
  // 1.b
  List ListB = initializeListB();

  printf("%d %d should be 0 0\n", ListA.count, ListB.count);

  // 2.b
  insertFirst(&ListA, 'E');
  insertFirst(&ListA, 'P');
  insertFirst(&ListA, 'O');
  insertFirst(&ListA, 'H');

  // 2.a
  printf("%d %d %d should be 0 1 3\n", 
    findElem(ListA, 'H'), findElem(ListA, 'O'), findElem(ListA, 'E'));

  displayList(ListA);
  // 2.c
  deleteElem(&ListA, 'Z');
  deleteElem(&ListA, 'H');
  deleteElem(&ListA, 'O');
  deleteElem(&ListA, 'E');
  deleteElem(&ListA, 'P');

  displayList(ListA);
}

void initializeListA(List *L) {
  L->count = 0;
}

List initializeListB(void) {
  List newList;
  newList.count = 0;
  return newList;
}

void displayList(List L) {
  int x;
  printf("[");
  for (x = 0; x < L.count; x++) {
    x < L.count - 1
    ? printf("%c, ", L.Elem[x])
    : printf("%c", L.Elem[x]);
  }
  puts("]");
}

/**
 * @brief Find the index of the first occurrence of a target element in the list.
 * 
 * @return int The index of the first occurrence of the target element, or -1 if not found.
 */
int findElem(List L, char target) {
  int x;

  for (x = 0; x < L.count && L.Elem[x] != target; x++) {}

  if (x != L.count) {
    return x;
  } else {
    return -1;
  }
}

/**
 * @brief Insert a new element at the beginning of the list.
 * 
 * If the list is not at its maximum capacity, existing elements are shifted
 * to the right to make space for the new element.
 */
void insertFirst(List *L, char newElem) {
  if (L->count < SIZE) {
    int x;

    for (x = L->count; x > 0; x--) {
      L->Elem[x] = L->Elem[x-1];
    }

    L->Elem[0] = newElem;
    L->count++;
  }
}

/**
 * @brief Delete the first occurrence of a specified element from the list.
 * 
 * The remaining elements are shifted to fill the gap.
 */
void deleteElem(List *L, char targetElem) {
  int x;

  for (x = 0; x < L->count && L->Elem[x] != targetElem; x++) {}

  if (x < L->count) {
    for (; x < L->count - 1; x++) {
      L->Elem[x] = L->Elem[x + 1];
    }

    L->count--;
  }
}