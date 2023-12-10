#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct node {
  int data;
  struct node *link;
} *Node;

typedef Node Graph[MAX];

void init(Graph G);
void addEdge(Graph G, int src, int dest);
bool edgeExists(Graph G, int src, int dest);
void display(Graph G);

int main(void) {
  Graph G;
  init(G);
  addEdge(G, 0, 1);
  addEdge(G, 4, 4);
  display(G);
}

void init(Graph G) {
  for (int row = 0; row < MAX; row++) {
    G[row] = NULL;
  }
}

void addEdge(Graph G, int src, int dest) {
  Node *trav;
  for (trav = &G[src]; *trav != NULL && (*trav)->data < dest;
       trav = &(*trav)->link) {
  }

  Node newNode = (Node)malloc(sizeof(struct node));
  if (newNode != NULL) {
    Node tmp = *trav;
    newNode->data = dest;
    newNode->link = *trav;
    *trav = newNode;
    free(tmp);
  }
}

bool edgeExists(Graph G, int src, int dest) {
  Node *trav;
  for (trav = &G[src]; *trav != NULL && (*trav)->data != dest;
       trav = &(*trav)->link) {
  }

  return *trav == NULL ? false : true;
}

void display(Graph G) {
  for (int row = 0; row < MAX; row++) {
    printf("%d [ ", row);
    Node trav;
    for (trav = G[row]; trav != NULL; trav = trav->link) {
      printf("%d ", trav->data);
    }
    printf("]\n");
  }
  puts("");
}