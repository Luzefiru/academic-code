#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int elem;
  struct node *LC;
  struct node *RC;
} *Node;

Node createNode(int data);
void insert(Node *node, int data);
void preOrder(Node node);
void inOrder(Node node);
void postOrder(Node node);
int sum(Node root);

int main(void) {
  Node tree = NULL;
  insert(&tree, 4);
  insert(&tree, 2);
  insert(&tree, 5);
  insert(&tree, 1);
  insert(&tree, 3);
  preOrder(tree);
  printf("\n");
  inOrder(tree);
  printf("\n");
  postOrder(tree);
  printf("\n");
  printf("Sum = %d\n", sum(tree));
}

Node createNode(int data) {
  struct node *newNode = malloc(sizeof(struct node));
  newNode->LC = NULL;
  newNode->RC = NULL;
  newNode->elem = data;
  return newNode;
}

void insert(Node *node, int data) {
  if (*node == NULL) {
    *node = createNode(data);
  } else if (data < (*node)->elem) {
    insert(&(*node)->LC, data);
  } else {
    insert(&(*node)->RC, data);
  }
}

void preOrder(Node node) {
  if (node != NULL) {
    printf("%d ", node->elem);
    preOrder(node->LC);
    preOrder(node->RC);
  }
}

void inOrder(Node node) {
  if (node != NULL) {
    inOrder(node->LC);
    printf("%d ", node->elem);
    inOrder(node->RC);
  }
}

void postOrder(Node node) {
  if (node != NULL) {
    postOrder(node->LC);
    postOrder(node->RC);
    printf("%d ", node->elem);
  }
}

int sum(Node root) {
  if (root == NULL) {
    return 0;
  }

  return root->elem + sum(root->LC) + sum(root->RC);
}