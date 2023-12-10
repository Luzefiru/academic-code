#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
  char data;
  struct node *link;
} NodeType, *Node;

typedef struct {
  Node front;
  Node rear;
} QueueType, *Queue;

void initQueue(Queue *Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue Q, char newElem);
char dequeue(Queue Q);
void displayQueue(Queue Q);
char front(Queue Q);

int main(void) {
  Queue Q;
  initQueue(&Q);
  printf("isEmpty? %d\n", isEmpty(Q));
  printf("isFull? %d\n", isFull(Q));
  enqueue(Q, 'I');
  enqueue(Q, 'A');
  enqueue(Q, 'N');
  displayQueue(Q);
  printf("front? %c\n", front(Q));
}

void initQueue(Queue *Q) {
  *Q = (Queue)malloc(sizeof(QueueType));
  if (*Q != NULL) {
    (*Q)->front = NULL;
    (*Q)->rear = NULL;
  }
}

bool isEmpty(Queue Q) { return Q->front == NULL && Q->rear == NULL; }

bool isFull(Queue Q) {
  Node trav;
  int count = 0;
  for (trav = Q->rear; trav != NULL && count < MAX; trav = trav->link) {
    count++;
  }

  return count >= MAX;
}

void enqueue(Queue Q, char newElem) {
  if (!isFull(Q)) {
    Node newNode = (Node)malloc(sizeof(NodeType));
    if (newNode != NULL) {
      newNode->data = newElem;
      newNode->link = NULL;

      if (Q->rear == NULL) {
        Q->front = newNode;
      } else {
        Q->rear->link = newNode;
      }
      Q->rear = newNode;
    }
  }
}

char dequeue(Queue Q) {
  char deletedElem = '\0';
  if (!isEmpty(Q)) {
    deletedElem = Q->front->data;
    Node tmp = Q->front;
    Q->front = Q->front->link;

    if (Q->front == NULL) {
      Q->rear = NULL;
    }
    free(tmp);
  }
  return deletedElem;
}

void displayQueue(Queue Q) {
  Queue buffer;
  char current;

  initQueue(&buffer);
  printf("[ ");
  while (!isEmpty(Q)) {
    current = dequeue(Q);
    printf("%c ", current);
    enqueue(buffer, current);
  }

  while (!isEmpty(buffer)) {
    enqueue(Q, dequeue(buffer));
  }
  printf("]\n");
}

char front(Queue Q) { return Q->front->data; }