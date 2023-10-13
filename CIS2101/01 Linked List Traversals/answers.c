#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char elem;
  struct node *link;
} ctype, *List;

List createNode(char val);
void displayListPN(List L);
void displayListPPN(List *L);
void deleteNodeIndex(List *L, int targetIndex);
void deleteNodeValue(List *L, char targetValue);
void deleteAllOccurences(List *L, char targetValue);
void updateNodeValue(List *L, char oldValue, char newValue);
void insertFirst(List *L, char value);
void insertLast(List *L, char value);
void insertSorted(List *L, char value);
void bubbleSort(List L);

int main(void) {
  ctype *n1 = createNode('H');
  ctype *n2 = createNode('O');
  ctype *n3 = createNode('P');
  ctype *n4 = createNode('E');
  n1->link = n2;
  n2->link = n3;
  n3->link = n4;
  List L = n1;

  // 1)
  List *p;
  List q;

  // 2)
  p = &L;

  // 3)
  q = L;

  printf("%c %c should be H H\n", (*p)->elem, q->elem);
  displayListPN(L);
  displayListPPN(&L);
  
  deleteNodeIndex(&L, 4);
  deleteNodeValue(&L, 'Z');

  updateNodeValue(&L, 'H', 'R');

  deleteAllOccurences(&L, 'R');

  insertFirst(&L, 'H');
  insertFirst(&L, 'H');
  insertFirst(&L, 'H');
  insertFirst(&L, 'H');
  deleteAllOccurences(&L, 'H');
  insertFirst(&L, 'H');
  insertLast(&L, 'R');

  bubbleSort(L);

  insertSorted(&L, 'F');
  insertSorted(&L, 'S');
  insertSorted(&L, 'A');
  insertSorted(&L, 'N');

  displayListPPN(&L);

  bubbleSort(L);
  displayListPPN(&L);
}

/**
 * @brief Create a new ctype * node with the value input.
 * 
 * @param val 
 * @return List 
 */
List createNode(char val) {
  List newNode = (ctype *) malloc(sizeof(char));
  newNode->link = NULL;
  newNode->elem = val;
  return newNode;
}

void insertFirst(List *L, char value) {
  List newNode = (ctype *)malloc(sizeof(ctype));
  newNode->elem = value;
  newNode->link = *L;

  *L = newNode;
}

void insertLast(List *L, char value) {
  List newNode = (List)malloc(sizeof(ctype));
  newNode->elem = value;
  newNode->link = NULL;

  List *trav;
  for (trav = L; *trav != NULL; trav = &(*trav)->link) {}

  *trav = newNode;
}

void insertSorted(List *L, char value) {
  List *trav;
  for (trav = L; *trav != NULL && (*trav)->elem < value; trav = &(*trav)->link) {}

  List newNode = (ctype *)malloc(sizeof(ctype));
  newNode->elem = value;
  newNode->link = *trav;
  *trav = newNode;
}

void deleteNodeIndex(List *L, int targetIndex) {
  List *trav = L;
  int currentIndex;
  // while we don't reach the end of the list & the targetIndex does not match the currentIndex
  for (currentIndex = 0; *trav != NULL && currentIndex != targetIndex; trav = &(*trav)->link, currentIndex++) {}

  // if trav does not point to a null address, then we can delete the node it points to
  if (*trav != NULL && currentIndex == targetIndex) {
    List tmp = *trav;
    *trav = tmp->link;
    free(tmp);
  } else {
    puts("Delete Error: Index does not exist!");
  }
}

void deleteNodeValue(List *L, char targetValue) {
  List *trav;

  // traverse the list until we find the targetValue in the current node, otherwise reach NULL
  for (trav = L; *trav != NULL && (*trav)->elem != targetValue; trav = &(*trav)->link) {}

  // if we end early, meaning the 2nd condition: currentElem = targetValue is true
  if (*trav != NULL) {
    List tmp = *trav;
    *trav = tmp->link;
    free(tmp);
  } else {
    puts("Delete Error: Target value does not exist!");
  }
}

void deleteAllOccurences(List *L, char targetValue) {
  List *trav;

  for (trav = L; *trav != NULL;) {
    if ((*trav)->elem == targetValue) {
      List tmp = *trav;
      *trav = tmp->link;
      free(tmp);
    } else {
      trav = &(*trav)->link;
    }
  }
}

void updateNodeValue(List *L, char oldValue, char newValue) {
  List *trav;
  for (trav = L; *trav != NULL && (*trav)->elem != oldValue; trav = &(*trav)->link) {}

  if (*trav != NULL) {
    (*trav)->elem = newValue;
  } else {
    puts("Update Error: There exists no node with that old value!");
  }
}

void displayListPN(List L) {
  List trav;
  for (trav = L; trav != NULL; trav = trav->link) {
    printf("[%c]->", trav->elem);
  }
  printf("NULL\n");
}

void displayListPPN(List *L) {
  List *trav;
  for (trav = L; *trav != NULL; trav = &(*trav)->link) {
    printf("[%c]->", (*trav)->elem);
  }
  printf("NULL\n");
}

void bubbleSort(List L) {
  List trav;
  int length = 0, x;
  for (trav = L; trav != NULL; trav = trav->link, length++) {} 
  
  for (x = 0; x < length; x++) {
    for (trav = L; trav->link != NULL; trav = trav->link) {
      if (trav->elem > trav->link->elem) {
        char tmp = trav->elem;
        trav->elem = trav->link->elem;
        trav->link->elem = tmp;
      }
    }
  }
}