#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
  char elements[SIZE];
  int count;
} List,
  *List2; // Exercise 3.1.a

typedef struct {
  char *elemPtr;
  int count;
} List3,  // Exercise 3.1.b
  *List4; // Exercise 3.1.c

typedef enum { TRUE, FALSE } Boolean;

void displayList(List L);
// Exercise 1.a
void initializeList1(List *L);
// Exercise 1.b
List initializeList1_2(void);
// Exercise 2.a
int findElem(List L, char target);
// Exercise 2.b
void insertFirst(List *L, char newElem);
// Exercise 2.c
Boolean deleteElem(List *L, char target);
// Exercise 3.2.a
List2 initializeList2(void) {
  List *newList = malloc(sizeof(List));
  newList->count = 0;
  return &newList;
}
// Exercise 3.2.b
List3 initializeList3(void) {
  char *newListElements = malloc(sizeof(char) * SIZE);
  List3 newList = { .elemPtr = newListElements, .count = 0 };
  return newList;
}
// Exercise 3.2.c
List4 initializeList4(void) {
  char *newListElements = malloc(sizeof(char) * SIZE);
  List3 *newList = malloc(sizeof(List3));
  newList->elemPtr = newListElements;
  newList->count = 0;
  return newList;
}

int main(void) {
  List list1;
  initializeList1(&list1);
  list1.count = 1;
  list1.elements[0] = 99;
  displayList(list1);

  List list2 = initializeList1_2();
  list2.count = 1;
  list2.elements[0] = 34;
  displayList(list2);

  List test = {{'h', 'o', 'p', 'e'}, 4};
  printf("%d\n", findElem(test, 'h'));
  insertFirst(&test, 'z');
  deleteElem(&test, 'a');
  displayList(test);
}

// Exercise 1.a
void initializeList1(List *L) {
  L->count = 0;
}

// Exercise 1.b
List initializeList1_2(void) {
  List newList = {.count = 0};
  return newList;
}

// Utility Function
void displayList(List L) {
  putchar('[');
  for (int x = 0; x < L.count; x++) {
    (x != L.count - 1) ? printf("%c, ", L.elements[x]) : printf("%c", L.elements[x]);
  }
  puts("]");
}

// Exercise 2.a
int findElem(List L, char target) {
  int x;
  for (x = 0; x < L.count && L.elements[x] != target; x++) {}
  return (x == L.count) ? -1 : x;
}

// Exercise 2.b
void insertFirst(List *L, char newElem) {
  if (L->count < SIZE) {
    int x;
    for (x = L->count; x > 0; x--) {
      L->elements[x] = L->elements[x-1]; // shift everything to the right
    }
    L->elements[0] = newElem; // add the new element to the first position
    L->count++; // increment count
  }
}

// Exercise 2.c
Boolean deleteElem(List *L, char target) {
  Boolean isDeleted = FALSE;

  if (L->count > 0) {
    int x;
    for (x = 0; x < L->count && L->elements[x] != target; x++) {}

    if (x != L->count) {
      for (; x < L->count-1; x++) {
        L->elements[x] = L->elements[x+1]; // shift everything to the left to cover up the deleted index
      }
      L->count--;
      isDeleted = TRUE;
    }
  }

  return isDeleted;
}