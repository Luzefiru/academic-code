#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  struct node *LC;
  struct node *RC;
  int data;
} *Node;

void initTree(Node *root);
void insert(Node *root, int newElem);
void preOrder(Node root);
void inOrder(Node root);
void postOrder(Node root);
bool isMember(Node root, int target);
void delete(Node *root, int target);

int main(void) {
  Node T;
  initTree(&T);
  insert(&T, 4);
  insert(&T, 2);
  insert(&T, 5);
  insert(&T, 1);
  printf("[ ");
  inOrder(T);
  printf("]\n");
  printf("isMember? %d\n", isMember(T, 4));
  delete (&T, 4);
  printf("[ ");
  inOrder(T);
  printf("]\n");
}

void initTree(Node *root) { *root = NULL; }

void insert(Node *root, int newElem) {
  if (*root == NULL) {
    Node newNode = (Node)malloc(sizeof(struct node));
    newNode->data = newElem;
    newNode->LC = NULL;
    newNode->RC = NULL;
    *root = newNode;
  } else if (newElem < (*root)->data) {
    insert(&(*root)->LC, newElem);
  } else {
    insert(&(*root)->RC, newElem);
  }
}

void preOrder(Node root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preOrder(root->LC);
    preOrder(root->RC);
  }
}

void inOrder(Node root) {
  if (root != NULL) {
    inOrder(root->LC);
    printf("%d ", root->data);
    inOrder(root->RC);
  }
}

void postOrder(Node root) {
  if (root != NULL) {
    postOrder(root->LC);
    postOrder(root->RC);
    printf("%d ", root->data);
  }
}

bool isMember(Node root, int target) {
  if (root != NULL && target < root->data) {
    isMember(root->LC, target);
  } else if (root != NULL && target > root->data) {
    isMember(root->RC, target);
  } else {
    return root != NULL;
  }
}

void delete(Node *root, int target) {
  Node *trav;
  for (trav = root; *trav != NULL && (*trav)->data != target;) {
    trav = target < (*trav)->data ? &(*trav)->LC : &(*trav)->RC;
  }

  if (*trav != NULL) {
    if ((*trav)->LC != NULL && (*trav)->RC != NULL) {
      Node *min;
      for (min = &(*trav)->RC; (*min)->LC != NULL; min = &(*min)->LC) {
      }
      (*trav)->data = (*min)->data;
      Node tmp = *min;
      *min = NULL;
      free(tmp);
    } else if ((*trav)->LC == NULL && (*trav)->RC == NULL) {
      printf("hello");
      // no children
      Node tmp = *trav;
      *trav = NULL;
      free(tmp);
    } else {
      // might have child on left or right, swap with it before freeing it
      Node tmp = *trav;
      *trav = (*trav)->LC != NULL ? (*trav)->LC : (*trav)->RC;
      free(tmp);
    }
  }
}