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
void sortList(List *L);
void deleteFirst(List *L);
void deleteLast(List *L);
void deleteAllOccurences(List *L, const char *targetID);
bool isMember(List L, const char *targetID);

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
  updateIdFirstOccurence(&L, "99", "69");
  insertFirst(&L, (studRec){"100"});
  sortList(&L);
  deleteFirst(&L);
  deleteLast(&L);
  displayList(L);
  // [1]->[2]->[4]->[5]->[69]->NULL
  insertSorted(&L, (studRec){"69"});
  insertFirst(&L, (studRec){"69"});
  deleteAllOccurences(&L, "69");
  displayList(L);
  printf("1 in List? %d\n", isMember(L, "1"));
  printf("4 in List? %d\n", isMember(L, "4"));
  printf("5 in List? %d\n", isMember(L, "5"));
  printf("69 in List? %d\n", isMember(L, "69"));
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

void sortList(List *L) {
  int max = 0, x;
  List *trav;
  for (trav = L; *trav != NULL; trav = &(*trav)->link) {
    max++;
  }

  for (x = 0; x < max; x++) {
    for (trav = L; (*trav)->link != NULL; trav = &(*trav)->link) {
      if (atoi((*trav)->stud.ID) > atoi((*trav)->link->stud.ID)) {
        char tmp[10];
        strcpy(tmp, (*trav)->stud.ID);
        strcpy((*trav)->stud.ID, (*trav)->link->stud.ID);
        strcpy((*trav)->link->stud.ID, tmp);
      }
    }
  }
}

void deleteFirst(List *L) {
  if (*L != NULL) {
    List tmp = *L;
    *L = (*L)->link;
    free(tmp);
  }
}

void deleteLast(List *L) {
  List *trav;
  for (trav = L; *trav != NULL && (*trav)->link != NULL;
       trav = &(*trav)->link) {
  }

  if (*trav != NULL) {
    List tmp = *trav;
    *trav = NULL;
    free(tmp);
  }
}

void deleteAllOccurences(List *L, const char *targetID) {
  List *trav;
  for (trav = L; *trav != NULL;) {
    if (strcmp((*trav)->stud.ID, targetID) == 0) {
      List tmp = *trav;
      *trav = tmp->link;
      free(tmp);
    } else {
      trav = &(*trav)->link;
    }
  }
}

bool isMember(List L, const char *targetID) {
  List trav;
  for (trav = L; trav != NULL && strcmp(targetID, trav->stud.ID) != 0;
       trav = trav->link) {
  }

  return trav == NULL ? false : true;
}