#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5
#define INF 99999

typedef int Graph[MAX][MAX];

typedef int Set[MAX];

void init(Graph G);
void addEdge(Graph G, int src, int dest, int weight);
bool edgeExists(Graph G, int src, int dest);
void display(Graph G);
void prims(Graph G, Graph MST);

int main(void) {
  Graph G, MST;
  init(G);
  init(MST);
  addEdge(G, 0, 1, 4);
  addEdge(G, 1, 2, 3);
  addEdge(G, 2, 3, 5);
  addEdge(G, 1, 4, 2);
  addEdge(G, 4, 3, 7);
  display(G);
  prims(G, MST);
  display(MST);
}

bool isFull(Set S) {
  bool isFull = 1;
  for (int i = 0; i < MAX && isFull; i++) {
    if (S[i] == 0) {
      isFull = 0;
    }
  }
  return isFull;
}

void prims(Graph G, Graph MST) {
  int numEdges = 0;
  Set visited = {0};
  visited[0] = 1;

  int x, y;
  while (numEdges < MAX - 1) {
    // For every vertex in the set S, find the all adjacent vertices
    //  calculate the distance from the vertex selected at step 1.
    //  if the vertex is already in the set S, discard it otherwise
    // choose another vertex nearest to selected vertex  at step 1.
    int min = INF; // set to INF at start
    x = 0;
    y = 0;
    // check through all vertices to find next vertex to connect to
    for (int i = 0; i < MAX; i++) {
      // only if the tail is in the current visited set
      if (visited[i]) {
        // we check for its adjacent vertices
        for (int j = 0; j < MAX; j++) {
          // if it's not yet visited & an edge exists
          if (!visited[j] && G[i][j]) {
            // if it's smaller than the current smallest
            if (min > G[i][j]) {
              // it becomes the new smallest & we save it for the MST
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    MST[x][y] = G[x][y]; // add the minimum & unvisited vertex to the MST
    visited[y] = true;   // mark it as visited
    numEdges++;          // go to next iteration
  }
}

void init(Graph G) {
  for (int row = 0; row < MAX; row++) {
    for (int col = 0; col < MAX; col++) {
      G[row][col] = 0;
    }
  }
}

void addEdge(Graph G, int src, int dest, int weight) { G[src][dest] = weight; }

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