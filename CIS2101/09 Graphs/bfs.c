#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 6

typedef int Graph[MAX][MAX];

typedef int Set[MAX];

typedef struct node {
  int data;
  struct node *link;
} *Node;

typedef struct queue {
  Node front;
  Node rear;
} *Queue;

void init(Graph G);
void addEdge(Graph G, int src, int dest);
void display(Graph G);
Queue initQueue(void);
void enq(Queue Q, int elem);
int deq(Queue Q);
bool isEmpty(Queue Q);
void bfs(Graph G, int root);

int main(void) {
  Graph G;
  init(G);
  addEdge(G, 1, 2);
  addEdge(G, 2, 5);
  addEdge(G, 1, 4);
  addEdge(G, 4, 3);
  display(G);
  bfs(G, 1);
}

void bfs(Graph G, int root) {
  // if node is visited, visited[node] == 1
  Set visited = {0};
  // a queue of the current nodes to process, before inserting to Set
  Queue Q = initQueue();
  if (Q != NULL) {
    // mark the root as visited & enqueue it
    visited[root] = 1;
    enq(Q, root);

    while (!isEmpty(Q)) {
      int x;
      for (x = 0; x < MAX; x++) {
        // if the current queue node is adjacent to node x & we didn't visit x
        if (G[Q->front->data][x] == 1 && !visited[x]) {
          visited[x] = 1; // mark x as visited
          enq(Q, x);      // enqueue x to visit all its nodes later
        }
      }
      // print the element we enqueued
      printf("%d ", deq(Q));
    }
  }
  puts("");
}

void init(Graph G) {
  for (int row = 0; row < MAX; row++) {
    for (int col = 0; col < MAX; col++) {
      G[row][col] = 0;
    }
  }
}

void addEdge(Graph G, int src, int dest) { G[src][dest] = 1; }

void display(Graph G) {
  printf("    ");
  for (int row = 0; row < MAX; row++) {
    printf("%d ", row);
  }
  puts("");
  for (int row = 0; row < MAX; row++) {
    printf("%d [ ", row);
    for (int col = 0; col < MAX; col++) {
      printf("%d ", G[row][col]);
    }
    printf("]\n");
  }
  puts("");
}

Queue initQueue(void) {
  Queue newQueue = (Queue)malloc(sizeof(Queue));
  if (newQueue != NULL) {
    newQueue->front = NULL;
    newQueue->rear = NULL;
  }
  return newQueue;
}

bool isEmpty(Queue Q) { return Q->front == NULL; }

void enq(Queue Q, int elem) {
  Node newNode = (Node)malloc(sizeof(struct node));
  if (newNode != NULL) {
    newNode->data = elem;
    newNode->link = NULL;
    if (Q->front == NULL) {
      Q->front = newNode;
    } else {
      Q->rear->link = newNode;
    }

    Q->rear = newNode;
  }
}

int deq(Queue Q) {
  int retval = -1;

  if (Q->front != NULL) {
    Node tmp = Q->front;
    Q->front = Q->front->link;
    retval = tmp->data;
    free(tmp);

    if (Q->front == NULL) {
      Q->rear = NULL;
    }
  }

  return retval;
}