#include <stdbool.h>
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
bool isMember(Node root, int target);
bool isMemberIterative(Node root, int target);
int min(Node root);
int max(Node root);

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
  printf("isMember(1) = %d\n", isMember(tree, 1));
  printf("isMember(4) = %d\n", isMember(tree, 4));
  printf("isMember(3) = %d\n", isMember(tree, 3));
  printf("isMember(99) = %d\n", isMember(tree, 99));
  printf("max() = %d\n", max(tree));
  printf("min() = %d\n", min(tree));
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

bool isMember(Node root, int target) {
  if (root != NULL && target < root->elem) {
    return isMember(root->LC, target);
  } else if (root != NULL && target > root->elem) {
    return isMember(root->RC, target);
  } else {
    return root == NULL ? false : true;
  }
}

bool isMemberIterative(Node root, int target) {
  while (root != NULL && root->elem != target) {
    if (target < root->elem) {
      root = root->LC;
    } else {
      root = root->RC;
    }
  }

  return root == NULL ? false : true;
}

int min(Node root) {
  if (root != NULL && root->LC == NULL) {
    return root->elem;
  }

  return min(root->LC);
}

int max(Node root) {
  if (root != NULL && root->RC == NULL) {
    return root->elem;
  }

  return max(root->RC);
}