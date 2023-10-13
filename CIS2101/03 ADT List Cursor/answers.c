#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
  int elem;
  int link;
} Nodetype;

typedef struct {
  int avail;
  Nodetype Nodes[SIZE];
} VirtualHeap;

typedef int List;

void initializeVH(VirtualHeap *VH);
void displayList(VirtualHeap VH, List L);
int allocSpace(VirtualHeap *VH);
void insertFirst(VirtualHeap *VH, List *L, char ch);
void insertLast(VirtualHeap *VH, List *L, char ch);
void bubbleSort(VirtualHeap *VH, List L);

int main(void) {
  VirtualHeap VH;
  initializeVH(&VH);

  List L = -1;
  displayList(VH, L);
  insertFirst(&VH, &L, 'C');
  insertLast(&VH, &L, 'B');
  insertLast(&VH, &L, 'A');
  bubbleSort(&VH, L);
  displayList(VH, L);
}

void insertFirst(VirtualHeap *VH, List *L, char ch) {
  int newNode = allocSpace(VH);

  if (newNode != -1) {
    VH->Nodes[newNode].elem = ch;
    VH->Nodes[newNode].link = *L;
    *L = newNode;
  }
}

void insertLast(VirtualHeap *VH, List *L, char ch) {
  int newNode = allocSpace(VH);

  if (newNode != -1) {
    List *trav;
    for (trav = L; *trav != -1; trav = &VH->Nodes[*trav].link) {}

    *trav = newNode;
    VH->Nodes[newNode].elem = ch;
    VH->Nodes[newNode].link = -1;
  }
}

void bubbleSort(VirtualHeap *VH, List L) {
  int length = 0, x, y;
  for (x = L; x != -1; x = VH->Nodes[x].link) {
    length++;
  }

  for (y = 0; y < length; y++) {
    for (x = L; VH->Nodes[x].link != -1; x = VH->Nodes[x].link) {
      if (VH->Nodes[x].elem > VH->Nodes[VH->Nodes[x].link].elem) {
        char tmp = VH->Nodes[x].elem;
        VH->Nodes[x].elem = VH->Nodes[VH->Nodes[x].link].elem;
        VH->Nodes[VH->Nodes[x].link].elem = tmp;
      }
    }
  }
}

void initializeVH(VirtualHeap *VH) {
  VH->avail = SIZE - 1;
  int x;
  for (x = SIZE - 1; x >= 0; x--) {
    VH->Nodes[x].elem = '\0';
    VH->Nodes[x].link = x - 1;
  }
}

int allocSpace(VirtualHeap *VH) {
  int retval = -1;
  if (VH->avail != -1) {
    retval = VH->avail;
    VH->avail = VH->Nodes[VH->avail].link;
  }
  return retval;
}

void deallocSpace(VirtualHeap *VH, int indexToFree) {
  VH->Nodes[indexToFree].link = VH->avail;
  VH->avail = indexToFree;
}

void displayList(VirtualHeap VH, List L) {
  int x;
  for (x = L; x != -1; x = VH.Nodes[x].link) {
    printf("(%c)->", VH.Nodes[x].elem);
  }
  printf("NULL\n");
}