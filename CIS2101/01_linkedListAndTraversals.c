#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char elem;
  struct node *link;
} ctype, *List;

void printLinkedList(List *head) {
  for (List cur = *head; cur != NULL; cur = cur->link) {
    printf("%zu(%c)->", cur, cur->elem);
  }
  puts("NULL");
}

int main(void) {
  List node1 = malloc(sizeof(ctype));
  List node2 = malloc(sizeof(ctype));
  List node3 = malloc(sizeof(ctype));
  List node4 = malloc(sizeof(ctype));
  node1->elem = 'H';
  node1->link = node2;
  node2->elem = 'O';
  node2->link = node3;
  node3->elem = 'P';
  node3->link = node4;
  node4->elem = 'E';
  node4->link = NULL;
  List L = node1;

  printLinkedList(&L);

  /* Exercises */

  // 1
  List *p;   // a pointer that points to a pointer
  List q;    // a pointer that points to a struct node
  
  // 2
  p = &L;    // make the pointer-pointer point to the head address
  printf("should have same address %zu -- %zu\n", *p, L);

  // 3
  q = node1; // make the struct pointer point to a struct address
  printf("should have same address %zu -- %zu\n", q, node1);
  printf("should be different %zu -- %zu\n", p, L);
}