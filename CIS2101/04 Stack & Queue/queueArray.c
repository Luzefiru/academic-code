#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
  int front;
  int rear;
  char Elem[MAX];
} Queue;

void initQueue(Queue *Q);
int isFull(Queue Q);
int isEmpty(Queue Q);
void enqueue(Queue *Q, char ch);
void dequeue(Queue *Q);
void makeNull(Queue *Q);
char front(Queue Q);
void displayQueue(Queue Q);

int main(void) {
  Queue q;
  initQueue(&q);
  enqueue(&q, 'I');
  enqueue(&q, 'A');
  enqueue(&q, 'N');
  displayQueue(q);
}

void displayQueue(Queue Q) {
  int x;
  for (x = Q.front; x <= Q.rear; x++) {
    printf("(%c)->", Q.Elem[x]);
  }
}

void initQueue(Queue *Q) {
  Q->front = 0;
  Q->rear = MAX - 1;
}

int isFull(Queue Q) {
  return (Q.rear + 2) % MAX == Q.front;
}

int isEmpty(Queue Q) {
  return (Q.rear + 1) % MAX == Q.front;
}

void enqueue(Queue *Q, char ch) {
  if (!isFull(*Q)) {
    Q->rear = (Q->rear + 1) % MAX;
    Q->Elem[Q->rear] = ch;
  }
}

void dequeue(Queue *Q) {
  if (!isEmpty(*Q)) {
    Q->front = (Q->front + 1) % MAX;
  }
}

void makeNull(Queue *Q) {
  Q->rear = (MAX - 1 + Q->front) % MAX;
}

char front(Queue Q) {
  return Q.Elem[Q.front];
}