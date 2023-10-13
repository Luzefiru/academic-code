#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
  char Elem[MAX];
  int top;
} Stack;

Stack initializeStack(void);
void push(Stack *s, char ch);
void pop(Stack *s);
char top(Stack s);
bool isEmpty(Stack s);
bool isFull(Stack s);
void displayStack(Stack s);

int main(void) {
  Stack s = initializeStack();
  push(&s, 'N');
  push(&s, 'A');
  push(&s, 'I');
  displayStack(s);
  printf("%c", top(s));
}

Stack initializeStack(void) {
  Stack newStack;
  newStack.top = -1;
  return newStack;
}

void push(Stack *s, char ch) {
  if (s->top < MAX - 1) {
    s->top++;
    s->Elem[s->top] = ch;
  }
}

void pop(Stack *s) {
  if (s->top != -1) {
    s->top--;
  }
}

char top(Stack s) {
  return s.Elem[s.top];
}

bool isEmpty(Stack s) {
  return s.top == -1;
}

bool isFull(Stack s) {
  return s.top == MAX - 1;
}

void displayStack(Stack s) {
  int x;
  printf("[");
  for (x = s.top; x >= 0; x--) {
    x != 0 ? printf("%c, ", s.Elem[x]) : printf("%c", s.Elem[x]);
  } 
  printf("]\n");
}