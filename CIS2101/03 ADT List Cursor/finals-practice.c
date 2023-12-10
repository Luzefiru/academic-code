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
  int link;
  studRec stud;
} NodeType;

typedef int List;

typedef struct heap {
  NodeType Node[MAX];
  List avail;
} *VirtualHeap;

void init(VirtualHeap *VH);
int allocSpace(VirtualHeap VH);
void deallocSpace(VirtualHeap VH, int indexToFree);
void displayList(VirtualHeap VH, List L);
// Copied
void insertFirst(VirtualHeap VH, List *L, studRec newStudent);
void insertLast(VirtualHeap VH, List *L, studRec newStudent);
void insertSorted(VirtualHeap VH, List *L, studRec newStudent);
void insertSortedUnique(VirtualHeap VH, List *L, studRec newStudent);
void updateId(VirtualHeap VH, List *L, const char *targetId, const char *newId);
void deleteFirst(VirtualHeap VH, List *L);
void deleteLast(VirtualHeap VH, List *L);
void deleteAllOccurences(VirtualHeap VH, List *L, const char *targetID);
bool isMember(VirtualHeap VH, List L, const char *targetID);

int main(void) {
  VirtualHeap VH;
  init(&VH);
  displayList(VH, VH->avail);

  List L = -1;
  insertFirst(VH, &L, (studRec){"2"});
  insertFirst(VH, &L, (studRec){"1"});
  insertLast(VH, &L, (studRec){"3"});
  displayList(VH, L);
  // [ 1 ]->(9)[ 2 ]->(7)[ 3 ]->(-1)
  insertSorted(VH, &L, (studRec){"9"});
  insertSorted(VH, &L, (studRec){"0"});
  displayList(VH, L);
  // [ 0 ]->(8)[ 1 ]->(9)[ 2 ]->(7)[ 3 ]->(6)[ 9 ]->(-1)
  insertSortedUnique(VH, &L, (studRec){"9"});
  insertSortedUnique(VH, &L, (studRec){"0"});
  insertSortedUnique(VH, &L, (studRec){"4"});
  insertSortedUnique(VH, &L, (studRec){"10"});
  displayList(VH, L);
  // [ 0 ]->(8)[ 1 ]->(9)[ 2 ]->(7)[ 3 ]->(4)[ 4 ]->(6)[ 9 ]->(3)[ 10 ]->(-1)
  updateId(VH, &L, "10", "9");
  updateId(VH, &L, "0", "9");
  displayList(VH, L);
  // [ 9 ]->(8)[ 1 ]->(9)[ 2 ]->(7)[ 3 ]->(4)[ 4 ]->(6)[ 9 ]->(3)[ 9 ]->(-1)
  deleteAllOccurences(VH, &L, "9");
  displayList(VH, L);
  // [ 1 ]->(9)[ 2 ]->(7)[ 3 ]->(4)[ 4 ]->(-1)
  deleteFirst(VH, &L);
  deleteFirst(VH, &L);
  deleteLast(VH, &L);
  displayList(VH, L);
  // [ 3 ]->(-1)
  printf("isMember 1? %d\n", isMember(VH, L, "1"));
  printf("isMember 3? %d\n", isMember(VH, L, "3"));
  printf("isMember 9? %d\n", isMember(VH, L, "9"));
  printf("isMember 44? %d\n", isMember(VH, L, "44"));
}

void init(VirtualHeap *VH) {
  *VH = (VirtualHeap)malloc(sizeof(struct heap));
  if (*VH != NULL) {
    (*VH)->avail = MAX - 1;
    int x;
    for (x = MAX - 1; x >= 0; x--) {
      (*VH)->Node[x].link = x - 1;
      (*VH)->Node[x].stud = (studRec){"X"};
    }
  }
}

int allocSpace(VirtualHeap VH) {
  int tmp = VH->avail;
  VH->avail = VH->Node[VH->avail].link;
  return tmp;
}

void deallocSpace(VirtualHeap VH, int indexToFree) {
  VH->Node[indexToFree].link = VH->avail;
  VH->avail = indexToFree;
}

void displayList(VirtualHeap VH, List L) {
  int x;
  for (x = L; x != -1; x = VH->Node[x].link) {
    printf("[ %s ]->(%d)", VH->Node[x].stud.ID, VH->Node[x].link);
  }
  puts("");
}

void insertFirst(VirtualHeap VH, List *L, studRec newStudent) {
  if (VH->avail != -1) {
    int newNode = VH->avail;
    VH->avail = VH->Node[VH->avail].link;

    VH->Node[newNode].stud = newStudent;
    VH->Node[newNode].link = *L;
    *L = newNode;
  }
}

void insertLast(VirtualHeap VH, List *L, studRec newStudent) {
  if (VH->avail != -1) {
    List *trav;
    for (trav = L; *trav != -1; trav = &VH->Node[*trav].link) {
    }

    List newNode = VH->avail;
    VH->avail = VH->Node[VH->avail].link;
    VH->Node[newNode].stud = newStudent;
    VH->Node[newNode].link = -1;
    *trav = newNode;
  }
}

void insertSorted(VirtualHeap VH, List *L, studRec newStudent) {
  if (VH->avail != -1) {
    List *trav;
    for (trav = L;
         *trav != -1 && atoi(VH->Node[*trav].stud.ID) < atoi(newStudent.ID);
         trav = &VH->Node[*trav].link) {
    }

    List newNode = VH->avail;
    VH->avail = VH->Node[VH->avail].link;
    VH->Node[newNode].stud = newStudent;
    VH->Node[newNode].link = *trav;
    *trav = newNode;
  }
}

void insertSortedUnique(VirtualHeap VH, List *L, studRec newStudent) {
  List *trav;
  for (trav = L;
       *trav != -1 && atoi(VH->Node[*trav].stud.ID) < atoi(newStudent.ID);
       trav = &VH->Node[*trav].link) {
  }

  if (*trav == -1 || atoi(VH->Node[*trav].stud.ID) != atoi(newStudent.ID)) {
    List newNode = VH->avail;
    VH->avail = VH->Node[VH->avail].link;
    VH->Node[newNode].stud = newStudent;
    VH->Node[newNode].link = *trav;
    *trav = newNode;
  }
}

void updateId(VirtualHeap VH, List *L, const char *targetId,
              const char *newId) {
  List *trav;
  for (trav = L; *trav != -1 && strcmp(VH->Node[*trav].stud.ID, targetId) != 0;
       trav = &VH->Node[*trav].link) {
  }

  if (*trav != -1) {
    strcpy(VH->Node[*trav].stud.ID, newId);
  }
}

void deleteFirst(VirtualHeap VH, List *L) {
  if (*L != -1) {
    List tmp = *L;
    *L = VH->Node[tmp].link;
    // free
    VH->Node[tmp].link = VH->avail;
    VH->avail = tmp;
  }
}

void deleteLast(VirtualHeap VH, List *L) {
  List *trav;
  for (trav = L; *trav != -1 && VH->Node[*trav].link != -1;
       trav = &VH->Node[*trav].link) {
  }

  if (*trav != -1) {
    List tmp = *trav;
    *trav = VH->Node[tmp].link;
    VH->Node[tmp].link = VH->avail;
    VH->avail = tmp;
  }
}

void deleteAllOccurences(VirtualHeap VH, List *L, const char *targetID) {
  List *trav;
  for (trav = L; *trav != -1;) {
    if (strcmp(VH->Node[*trav].stud.ID, targetID) == 0) {
      List tmp = *trav;
      *trav = VH->Node[*trav].link;
      VH->Node[tmp].link = VH->avail;
      VH->avail = tmp;
    } else {
      trav = &VH->Node[*trav].link;
    }
  }
}

bool isMember(VirtualHeap VH, List L, const char *targetID) {
  List trav;
  for (trav = L; trav != -1 && atoi(VH->Node[trav].stud.ID) != atoi(targetID);
       trav = VH->Node[trav].link) {
  }

  return trav == -1 ? false : true;
}