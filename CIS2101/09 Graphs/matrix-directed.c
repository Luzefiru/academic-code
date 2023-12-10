#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef int Graph[MAX][MAX];

void init(Graph G);
void addEdge(Graph G, int src, int dest);
bool edgeExists(Graph G, int src, int dest);
void display(Graph G);

int main(void) {
  Graph G;
  init(G);
  addEdge(G, 0, 1);
  display(G);
}

void init(Graph G) {
  for (int row = 0; row < MAX; row++) {
    for (int col = 0; col < MAX; col++) {
      G[row][col] = 0;
    }
  }
}

void addEdge(Graph G, int src, int dest) { G[src][dest] = 1; }

bool edgeExists(Graph G, int src, int dest) {
  return G[src][dest] == 1 ? true : false;
}

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