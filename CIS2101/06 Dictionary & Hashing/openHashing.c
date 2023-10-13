#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct node {
  struct node *link;
  int data;
} Node, *List;

typedef int Set[SIZE];
typedef List Dictionary[SIZE];

int hash(int value);
void initDic(Dictionary D);
void displayDic(Dictionary D);
void insert(Dictionary D, int valueToInsert);
void populateDic(Dictionary D, Set values);
void delete(Dictionary D, int valueToDelete);
int isMember(Dictionary D, int value);

int main(void) {
  Dictionary D;
  initDic(D);
  displayDic(D);

  Set A = { 0, 13, 20, 28, 30, 33, 45, 48, 108 };
  populateDic(D, A);
  delete(D, 108);
  displayDic(D);
  printf("%d", isMember(D, 11));
}

int hash(int value) {
  return (value * 31 + 7) % SIZE;
}

void initDic(Dictionary D) {
  int x;
  for (x = 0; x < SIZE; x++) {
    D[x] = NULL;
  }
}

void displayDic(Dictionary D) {
  int x;
  for (x = 0; x < SIZE; x++) {
    List *trav;
    printf("[%d] ", x);
    for (trav = &D[x]; *trav != NULL; trav = &(*trav)->link) {
      printf("(%d)->", (*trav)->data);
    }
    printf("NULL\n");
  }
}

void insert(Dictionary D, int valueToInsert) {
  int indexToInsert = hash(valueToInsert);

  List *trav = &D[indexToInsert];
  for (; *trav != NULL && valueToInsert > (*trav)->data; trav = &(*trav)->link) {
  }

  if (*trav == NULL || (*trav)->data != valueToInsert) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = valueToInsert;
    newNode->link = *trav;
    *trav = newNode;
  }
}

void delete(Dictionary D, int valueToDelete) {
  int targetIndex = hash(valueToDelete);

  List *trav = &D[targetIndex];
  for (; *trav != NULL && valueToDelete > (*trav)->data; trav = &(*trav)->link) {}

  if (*trav != NULL && (*trav)->data == valueToDelete) {
    List tmp = *trav;
    *trav = tmp->link;
    free(tmp);
  } 
}

void populateDic(Dictionary D, Set values) {
  int x;
  for (x = 0; x < SIZE; x++) {
    insert(D, values[x]);
  }
}

int isMember(Dictionary D, int value) {
  int targetIndex = hash(value);

  List *trav = &D[targetIndex];
  for (; *trav != NULL && (*trav)->data < value; trav = &(*trav)->link) {}

  return *trav == NULL ? 0 : 1;
}