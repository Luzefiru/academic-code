#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char FN[24], LN[16], MI;
} nameType;

typedef struct {
  char ID[10];
  nameType name;
  char course[8]; // BSCS, BSIS, BSIT only
  int yrLevel;
} studRec;

typedef struct node {
  studRec stud;
  struct node *link;
} NodeType, *List;

void init(List *L);
List createNode(studRec newStudent);
void displayList(List L);
void insertFirst(List *L, studRec newStudent);
void insertLast(List *L, studRec newStudent);
void insertSorted(List *L, studRec newStudent);
void insertSortedUnique(List *L, studRec newStudent);
void updateIdFirstOccurence(List *L, const char *targetId, const char *newId);

int main(void) {
  List L;
  init(&L);
  displayList(L);
  // NULL
  insertLast(&L, (studRec){"2"});
  insertFirst(&L, (studRec){"1"});
  displayList(L);
  // [1]->[2]->NULL
  insertSorted(&L, (studRec){"5"});
  insertSorted(&L, (studRec){"4"});
  insertSortedUnique(&L, (studRec){"0"});
  insertSortedUnique(&L, (studRec){"0"});
  insertSortedUnique(&L, (studRec){"99"});
  displayList(L);
  // [0]->[1]->[2]->[4]->[5]->[99]->NULL
}

void init(List *L) { *L = NULL; }

List createNode(studRec newStudent) {
  List newNode = (List)malloc(sizeof(struct node));
  newNode->stud = newStudent;
  newNode->link = NULL;
  return newNode;
}

void displayList(List L) {
  List trav;
  for (trav = L; trav != NULL; trav = trav->link) {
    printf("[%s]->", trav->stud.ID);
  }
  printf("NULL\n");
}

void insertFirst(List *L, studRec newStudent) {
  List newNode = (List)malloc(sizeof(NodeType));
  if (newNode != NULL) {
    newNode->stud = newStudent;
    newNode->link = *L;
    *L = newNode;
  }
}

void insertLast(List *L, studRec newStudent) {
  List *trav;
  for (trav = L; (*trav) != NULL; trav = &(*trav)->link) {
  }

  List newNode = (List)malloc(sizeof(struct node));
  if (newNode != NULL) {
    newNode->stud = newStudent;
    newNode->link = NULL;
    *trav = newNode;
  }
}

void insertSorted(List *L, studRec newStudent) {
  List *trav = L;
  for (trav = L; *trav != NULL && strcmp(newStudent.ID, (*trav)->stud.ID) > 0;
       trav = &(*trav)->link) {
  }

  List newNode = (List)malloc(sizeof(struct node));
  if (newNode != NULL) {
    newNode->stud = newStudent;
    newNode->link = *trav;
    *trav = newNode;
  }
}

void insertSortedUnique(List *L, studRec newStudent) {
  List *trav;
  for (trav = L; *trav != NULL && strcmp((*trav)->stud.ID, newStudent.ID) < 0;
       trav = &(*trav)->link) {
  }

  if (*trav == NULL || strcmp((*trav)->stud.ID, newStudent.ID) != 0) {
    List newNode = (List)malloc(sizeof(struct node));
    if (newNode != NULL) {
      newNode->stud = newStudent;
      newNode->link = *trav;
      *trav = newNode;
    }
  }
}

void updateIdFirstOccurence(List *L, const char *targetId, const char *newId) {
  List *trav;
  for (trav = L; *trav != NULL && strcmp((*trav)->stud.ID, targetId) != 0;
       trav = &(*trav)->link) {
  }

  if (*trav != NULL) {
    strcpy((*trav)->stud.ID, newId);
  }
}