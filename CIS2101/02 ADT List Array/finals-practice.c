#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct {
  char FN[24], LN[16], MI;
} nameType;

typedef struct {
  char ID[10];
  nameType name;
  char course[8]; // BSCS, BSIS, BSIT only
  int yrLevel;
} studRec;

typedef struct {
  studRec elem[MAX];
  int size;
} ListType, *List;

void init(List *L);
void displayList(List L);
void insertLast(List L, studRec newStudent);
void insertFirst(List L, studRec newStudent);
void insertUniqueLast(List L, studRec newStudent);
void sort(List L);
void insertUniqueSorted(List L, studRec newStudent);
bool isMember(List L, const char *targetID);
void delete(List L, const char *targetID);
void deleteAllOccurences(List L, const char *targetID);

int main(void) {
  List L;
  init(&L);
  insertLast(L, (studRec){"1"});
  insertFirst(L, (studRec){"3"});
  insertUniqueLast(L, (studRec){"8"});
  displayList(L);
  // [ 3 1 9 ]
  sort(L);
  displayList(L);
  // [ 1 3 9 ]
  insertUniqueSorted(L, (studRec){"3"});
  insertUniqueSorted(L, (studRec){"0"});
  insertUniqueSorted(L, (studRec){"5"});
  insertUniqueSorted(L, (studRec){"2"});
  insertUniqueSorted(L, (studRec){"9"});
  displayList(L);
  // [ 0 1 2 3 5 8 9 ]
  delete (L, "0");
  delete (L, "9");
  delete (L, "2");
  displayList(L);
  // [ 1 3 5 8 ]
  deleteAllOccurences(L, "8");
  deleteAllOccurences(L, "3");
  deleteAllOccurences(L, "1");
  displayList(L);
  insertFirst(L, (studRec){"1"});
  insertUniqueSorted(L, (studRec){"3"});
  insertFirst(L, (studRec){"5"});
  insertFirst(L, (studRec){"5"});
  displayList(L);
  deleteAllOccurences(L, "5");
  displayList(L);
}

void init(List *L) {
  *L = (List)malloc(sizeof(ListType));
  if (*L != NULL) {
    (*L)->size = 0;
  }
}

void displayList(List L) {
  int x;
  printf("[ ");
  for (x = 0; x < L->size; x++) {
    printf("%s ", L->elem[x].ID);
  }
  printf("]\n");
}

void insertLast(List L, studRec newStudent) {
  if (L->size < MAX) {
    L->elem[L->size++] = newStudent;
  }
}

void insertFirst(List L, studRec newStudent) {
  if (L->size < MAX) {
    int x;
    for (x = L->size++; x > 0; x--) {
      L->elem[x] = L->elem[x - 1];
    }
    L->elem[0] = newStudent;
  }
}

void insertUniqueLast(List L, studRec newStudent) {
  if (L->size < MAX) {
    int x;
    for (x = 0; x < L->size && strcmp(L->elem[x].ID, newStudent.ID) != 0; x++) {
    }

    if (x == L->size) {
      L->elem[x] = newStudent;
      L->size++;
    }
  }
}

void sort(List L) {
  int x, y;
  for (x = 0; x < L->size; x++) {
    for (y = 0; y < L->size - x - 1; y++) {
      if (atoi(L->elem[y].ID) > atoi(L->elem[y + 1].ID)) {
        studRec tmp = L->elem[y];
        L->elem[y] = L->elem[y + 1];
        L->elem[y + 1] = tmp;
      }
    }
  }
}

void insertUniqueSorted(List L, studRec newStudent) {
  if (L->size < MAX) {
    int target, x;
    // traverse to the end while checking if element is not sorted
    for (target = 0;
         target < L->size && strcmp(L->elem[target].ID, newStudent.ID) < 0;
         target++) {
    }

    // check if the current index is unique, otherwise it's the insert index
    if (strcmp(L->elem[target].ID, newStudent.ID) != 0) {
      // starting from size++, we shift all elements until we reach insert index
      for (x = L->size++; x > target; x--) {
        L->elem[x] = L->elem[x - 1];
      }
      L->elem[x] = newStudent;
    }
  }
}

bool isMember(List L, const char *targetID) {
  int x;
  for (x = 0; x < L->size && strcmp(L->elem[x].ID, targetID) < 0; x++) {
  }

  return x != MAX ? true : false;
}

void delete(List L, const char *targetID) {
  int x;
  for (x = 0; x < L->size && strcmp(L->elem[x].ID, targetID) < 0; x++) {
  }

  if (x < L->size && strcmp(L->elem[x].ID, targetID) == 0) {
    for (; x < L->size - 1; x++) {
      L->elem[x] = L->elem[x + 1];
    }
    L->size--;
  }
}

void deleteAllOccurences(List L, const char *targetID) {
  int x, y;
  for (x = 0; x < L->size;) {
    if (strcmp(targetID, L->elem[x].ID) == 0) {
      for (y = x; y < L->size - 1; y++) {
        L->elem[y] = L->elem[y + 1];
      }
      L->size--;
    } else {
      x++;
    }
  }
}