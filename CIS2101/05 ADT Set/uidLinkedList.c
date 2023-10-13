#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  struct node *link;
  char data;
} Node, *Set;

Set initSet(void);
void displaySet(Set S);
void insertSet(Set *S, char ch);
Set setUnionV1(Set *S1, Set *S2);
Set setIntersection(Set S1, Set S2);
Set setDifference(Set S1, Set S2);
int isInSet(Set S, char elem);

int main(void) {
  Set s1 = initSet();
  insertSet(&s1, 'A');
  insertSet(&s1, 'B');
  insertSet(&s1, 'C');
  Set s2 = initSet();
  insertSet(&s2, 'A');
  insertSet(&s2, 'E');
  insertSet(&s2, 'F');
  insertSet(&s2, 'G');

  displaySet(s1);
  displaySet(s2);

  displaySet(setUnionV1(&s1, &s2));
  displaySet(setIntersection(s1, s2));
  displaySet(setDifference(s1, s2));
}

Set initSet(void) {
  Set newSet = NULL;
  return newSet;
}

void insertSet(Set *S, char ch) {
  Set *trav;
  for (trav = S; *trav != NULL && (*trav)->data != ch; trav = &(*trav)->link) {}

  if (*trav == NULL) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = ch;
    newNode->link = NULL;
    *trav = newNode;
  }
}

Set setUnionV1(Set *S1, Set *S2) {
  Set newSet = initSet(), *trav;
  for (trav = S1; *trav != NULL; trav = &(*trav)->link) {
    insertSet(&newSet, (*trav)->data);
  }
  for (trav = S2; *trav != NULL; trav = &(*trav)->link) {
    insertSet(&newSet, (*trav)->data);
  }
  return newSet;
}

int isInSet(Set S, char elem) {
  int retval = 0;

  Set trav;
  for (trav = S; trav != NULL && trav->data != elem; trav = trav->link) {}

  if (trav != NULL) {
    retval = 1;
  }

  return retval;
}

Set setIntersection(Set S1, Set S2) {
  Set newSet = initSet(), trav;

  for (trav = S1; trav != NULL; trav = trav->link) {
    if (isInSet(S2, trav->data)) {
      insertSet(&newSet, trav->data);
    }
  }

  for (trav = S2; trav != NULL; trav = trav->link) {
    if (isInSet(S1, trav->data)) {
      insertSet(&newSet, trav->data);
    }
  }

  return newSet;
}

Set setDifference(Set S1, Set S2) {
  Set newSet = initSet(), trav;

  for (trav = S1; trav != NULL; trav = trav->link) {
    if (!isInSet(S2, trav->data)) {
      insertSet(&newSet, trav->data);
    }
  }
  
  return newSet;
}

void displaySet(Set S) {
  Set trav;
  printf("{ ");
  for (trav = S; trav != NULL; trav = trav->link) {
    printf("%c ", trav->data);
  }
  printf("}\n");
}