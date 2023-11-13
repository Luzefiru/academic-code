#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char data;
  struct node *link;
} ctype, *List;

List createNode(char val);
void displayListPN(List L);
void displayListPPN(List *L);
void deleteNodeIndex(List *L, int targetIndex);
void deleteNodeValue(List *L, char targetValue);
void deleteAllOccurrences(List *L, char targetValue);
void updateNodeValue(List *L, char oldValue, char newValue);
void insertFirst(List *L, char value);
void insertLast(List *L, char value);
void insertSorted(List *L, char value);
void insertSortedUnique(List *L, char value);
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

  printf("%c %c should be H H\n", (*p)->data, q->data);
  displayListPN(L);
  displayListPPN(&L);
  
  deleteNodeIndex(&L, 4);
  deleteNodeValue(&L, 'Z');

  updateNodeValue(&L, 'H', 'R');

  deleteAllOccurrences(&L, 'R');

  insertFirst(&L, 'H');
  insertFirst(&L, 'H');
  insertFirst(&L, 'H');
  insertFirst(&L, 'H');
  deleteAllOccurrences(&L, 'H');
  insertFirst(&L, 'H');
  insertLast(&L, 'R');

  bubbleSort(L);

  insertSortedUnique(&L, 'A');
  insertSortedUnique(&L, 'F');
  insertSortedUnique(&L, 'S');

  displayListPPN(&L);

  bubbleSort(L);
  displayListPPN(&L);
}

/**
 * @brief Create a new node with the given character value.
 * 
 * @param val The character value for the new node.
 * @return List A pointer to the newly created node.
 */
List createNode(char val) {
  List newNode = (ctype *) malloc(sizeof(char));
  newNode->link = NULL;
  newNode->data = val;
  return newNode;
}

/**
 * @brief Insert a new node with the given value at the beginning of the list.
 * 
 * @param L Pointer to the head of the list.
 * @param value The character value to be inserted.
 */
void insertFirst(List *L, char value) {
  List newNode = (ctype *)malloc(sizeof(ctype));
  newNode->data = value;
  newNode->link = *L;

  *L = newNode;
}

/**
 * @brief Insert a new node with the given value at the end of the list.
 * 
 * @param L Pointer to the head of the list.
 * @param value The character value to be inserted.
 */
void insertLast(List *L, char value) {
  List *trav;
  for (trav = L; *trav != NULL; trav = &(*trav)->link) {}

  List newNode = (List)malloc(sizeof(ctype));
  newNode->data = value;
  newNode->link = NULL;

  *trav = newNode;
}

/**
 * @brief Insert a new node with the given value in sorted order.
 * 
 * @param L Pointer to the head of the list.
 * @param value The character value to be inserted.
 */
void insertSorted(List *L, char value) {
  List *trav;
  for (trav = L; *trav != NULL && (*trav)->data < value; trav = &(*trav)->link) {}

  List newNode = (ctype *)malloc(sizeof(ctype));
  newNode->data = value;
  newNode->link = *trav;
  *trav = newNode;
}

/**
 * @brief Insert a new node with the given value in sorted order, ensuring uniqueness.
 * 
 * @param L Pointer to the head of the list.
 * @param value The character value to be inserted.
 */
void insertSortedUnique(List *L, char value) {
  List *trav;
  for (trav = L; *trav != NULL && value > (*trav)->data; trav = &(*trav)->link) {}

  if (*trav == NULL || value != (*trav)->data) {
    List newNode = (ctype *)malloc(sizeof(ctype));
    newNode->data = value;
    newNode->link = *trav;
    *trav = newNode;
  }
}

/**
 * @brief Delete the node at the specified index.
 * 
 * @param L Pointer to the head of the list.
 * @param targetIndex The index of the node to be deleted.
 */
void deleteNodeIndex(List *L, int targetIndex) {
  List *trav = L;
  int currentIndex;

  for (currentIndex = 0; *trav != NULL && currentIndex != targetIndex; trav = &(*trav)->link, currentIndex++) {}

  if (*trav != NULL && currentIndex == targetIndex) {
    List tmp = *trav;
    *trav = tmp->link;
    free(tmp);
  } else {
    puts("Delete Error: Index does not exist!");
  }
}

/**
 * @brief Delete the first occurrence of a node with the specified value.
 * 
 * @param L Pointer to the head of the list.
 * @param targetValue The value to be deleted.
 */
void deleteNodeValue(List *L, char targetValue) {
  List *trav;

  for (trav = L; *trav != NULL && (*trav)->data != targetValue; trav = &(*trav)->link) {}

  if (*trav != NULL) {
    List tmp = *trav;
    *trav = tmp->link;
    free(tmp);
  } else {
    puts("Delete Error: Target value does not exist!");
  }
}

/**
 * @brief Delete all occurrences of nodes with the specified value.
 * 
 * @param L Pointer to the head of the list.
 * @param targetValue The value to be deleted.
 */
void deleteAllOccurrences(List *L, char targetValue) {
  List *trav;

  for (trav = L; *trav != NULL;) {
    if ((*trav)->data == targetValue) {
      List tmp = *trav;
      *trav = tmp->link;
      free(tmp);
    } else {
      trav = &(*trav)->link;
    }
  }
}

/**
 * @brief Update the value of the first node with the specified old value.
 * 
 * @param L Pointer to the head of the list.
 * @param oldValue The value to be updated.
 * @param newValue The new value to be assigned.
 */
void updateNodeValue(List *L, char oldValue, char newValue) {
  List *trav;
  for (trav = L; *trav != NULL && (*trav)->data != oldValue; trav = &(*trav)->link) {}

  if (*trav != NULL) {
    (*trav)->data = newValue;
  } else {
    puts("Update Error: There exists no node with that old value!");
  }
}

/**
 * @brief Display the elements of the list in the order of pointer notation.
 * 
 * @param L The head of the list.
 */
void displayListPN(List L) {
  List trav;
  for (trav = L; trav != NULL; trav = trav->link) {
    printf("[%c]->", trav->data);
  }
  printf("NULL\n");
}

/**
 * @brief Display the elements of the list in the order of double pointer notation.
 * 
 * @param L Pointer to the head of the list.
 */
void displayListPPN(List *L) {
  List *trav;
  for (trav = L; *trav != NULL; trav = &(*trav)->link) {
    printf("[%c]->", (*trav)->data);
  }
  printf("NULL\n");
}

/**
 * @brief Sort the list using the bubble sort algorithm.
 * 
 * @param L The head of the list.
 */
void bubbleSort(List L) {
  List trav;
  int length = 0, x;
  for (trav = L; trav != NULL; trav = trav->link, length++) {} 
  
  for (x = 0; x < length; x++) {
    for (trav = L; trav->link != NULL; trav = trav->link) {
      if (trav->data > trav->link->data) {
        char tmp = trav->data;
        trav->data = trav->link->data;
        trav->link->data = tmp;
      }
    }
  }
}