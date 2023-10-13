#include <stdio.h>
#include <stdlib.h>

// 1
typedef struct node {
  char data;
  struct node *link;
} Node;

typedef struct {
  Node *front;
  Node *rear;
} Queue;

void initQueue(Queue *Q);
void displayQueue(Queue Q);
void enqueue(Queue *Q, char ch);
void dequeue(Queue *Q);
char front(Queue Q);

int main(void) {
  Queue q;
  initQueue(&q);

  enqueue(&q, 'I');
  printf("%p\n", q.rear);
  enqueue(&q, 'A');
  printf("%p\n", q.rear);
  enqueue(&q, 'N');
  printf("%p\n", q.rear);

  dequeue(&q);
  dequeue(&q);

  displayQueue(q);
  printf("%c\n", front(q));
}

void displayQueue(Queue Q) {
  Node *trav;
  printf("HEAD: ");
  for (trav = Q.front; trav != NULL; trav = trav->link) {
    printf("(%c)->", trav->data);
  }
  printf(" :REAR\n");
}

// 2.a
void initQueue(Queue *Q) {
  Q->front = NULL;
  Q->rear = NULL;
}

// 2.b
void enqueue(Queue *Q, char ch) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode != NULL) {
    newNode->data = ch;
    newNode->link = NULL;

    if (Q->front == NULL) {
      Q->front = newNode;
    } else {
      // point to the previous rear: (prevRear)->(newRear)->NULL
      Q->rear->link = newNode;
    }

    // let the rear point to the enqueued Node
    Q->rear = newNode;
  }
}

// 2.c
void dequeue(Queue *Q) {
  if (Q->front != NULL) {
    // save the next Node after the front
    Node *tmp = Q->front->link;
    // delete the front
    free(Q->front);
    // make the front the previously deleted link
    Q->front = tmp;

    if (Q->front == NULL) {
      Q->rear = NULL;
    }
  }
}

// 2.d
char front(Queue Q) {
  return Q.front != NULL ? Q.front->data : '\0';
}