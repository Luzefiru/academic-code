#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef enum {TRUE, FALSE} Boolean;

typedef struct {
  char elements[SIZE];
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
    x < L.count - 1 ? printf("%c, ", L.elements[x]) : printf("%c", L.elements[x]);
  }
  puts("]");
}

int findElem(List L, char target) {
  int x;
  for (x = 0; x < L.count && L.elements[x] != target; x++) {}

  if (x != L.count) {
    return x;
  }
}

void insertFirst(List *L, char newElem) {
  if (L->count < SIZE) {
    int x;
    for (x = L->count; x > 0; x--) {
      L->elements[x] = L->elements[x-1];
    }
    L->elements[0] = newElem;
    L->count++;
  }
}

void deleteElem(List *L, char targetElem) {
  int x;
  for (x = 0; x < L->count && L->elements[x] != targetElem; x++) {}

  if (x < L->count) {
    for (; x < L->count - 1; x++) {
      L->elements[x] = L->elements[x + 1];
    }
    L->count--;
  }
}