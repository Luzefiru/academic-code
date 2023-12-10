#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
  char Elem[MAX];
  int top;
} Stack, *StackPtr;

void initializeStack(StackPtr S);
void push(StackPtr S, char newElem);
char pop(StackPtr S);
char top(StackPtr S);
bool isEmpty(StackPtr S);
bool isFull(StackPtr S);
void displayStack(Stack S);

int main(void) {
  Stack S;
  initializeStack(&S);
  push(&S, 'N');
  push(&S, 'A');
  push(&S, 'I');
  displayStack(S);
}

void initializeStack(StackPtr S) { S->top = -1; }

void push(StackPtr S, char newElem) {
  if (S->top < MAX - 1) {
    S->Elem[++S->top] = newElem;
  }
}

char pop(StackPtr S) { return (S->top != -1) ? S->Elem[S->top--] : '\0'; }

char top(StackPtr S) { return (S->top != -1) ? S->Elem[S->top] : '\0'; }
bool isEmpty(StackPtr S) { return S->top == -1; }
bool isFull(StackPtr S) { return S->top >= MAX - 1; }

void displayStack(Stack S) {
  Stack buffer;
  char current;

  printf("[ ");
  while (!isEmpty(&S)) {
    current = pop(&S);
    printf("%c ", current);
    push(&buffer, current);
  }
  while (!isEmpty(&buffer)) {
    push(&S, pop(&buffer));
  }
  printf("]\n");
}