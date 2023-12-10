#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 6

typedef int Graph[MAX][MAX];

typedef int Set[MAX];

void init(Graph G);
void addEdge(Graph G, int src, int dest);
void display(Graph G);
bool isEmpty(Stack Q);
void dfs(Graph G, int root, Set visited);

int main(void) {
  Graph G;
  Set visited = {0};
  init(G);
  addEdge(G, 1, 2);
  addEdge(G, 2, 3);
  addEdge(G, 3, 1);
  addEdge(G, 3, 4);
  addEdge(G, 4, 5);
  addEdge(G, 5, 2);
  display(G);
  dfs(G, 1, visited);
}

void dfs(Graph G, int root, Set visited) {

  visited[root] = 1;
  printf("%d ", root);
  int x;
  for (x = 0; x < MAX; x++) {
    // if the node is adjacent & we didn't visit it yet
    if (G[root][x] == 1 && !visited[x]) {
      dfs(G, x, visited);
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
