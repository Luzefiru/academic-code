#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} NodeType, *Node;

int sum(Node root);
Node createNode(int data);

int main(void) {
  Node root;
  
  Node node4 = createNode(5);
  Node node5 = createNode(6);
  Node node3 = createNode(3);
  node3->left = node4;
  node3->right = node5;
  Node node2 = createNode(4);
  Node node1 = createNode(5);
  node1->left = node2;
  node1->right = node3;

  root = node1;

  printf("%d", sum(root));
}

int sum(Node root) {
  if (root == NULL) {
    return 0;
  }

  return root->data + sum(root->left) + sum(root->right);
}

Node createNode(int data) {
  Node newNode = malloc(sizeof(NodeType));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}