#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef int List;

typedef struct node {
  char data;
  int link;
} Node;

typedef struct {
  Node *Nodes;
  List Avail;
} VirtualHeap;


VirtualHeap initHeap();
void displayList(VirtualHeap VH, List L);
int alloc(VirtualHeap *VH);
void dealloc(VirtualHeap *VH, int targetIndex);
void insertFirst(VirtualHeap *VH, List *L, char elem);
void sortList(VirtualHeap *VH, List L);
void clearList(VirtualHeap *VH, List *L);

int main(void) {
  VirtualHeap VH = initHeap();

  puts("Avail at the start:");
  displayList(VH, VH.Avail); // prints VH->Avail list
  puts("");

  List L = -1;
  insertFirst(&VH, &L, 'a');
  insertFirst(&VH, &L, 'b');
  insertFirst(&VH, &L, 'c');
  puts("New List L:");
  displayList(VH, L); // prints L list
  puts("Avail:");
  displayList(VH, VH.Avail); // prints VH->Avail list
  puts("");

  puts("L after sorting:");
  sortList(&VH, L);
  displayList(VH, L); // prints L list
  puts("");

  puts("Avail after clearing L:");
  clearList(&VH, &L);
  displayList(VH, VH.Avail); // prints VH->Avail list
  puts("L after clearing:");
  displayList(VH, L); // prints L list
}

// returns an initialized VirtualHeap with MAX number of Nodes
VirtualHeap initHeap() {
  VirtualHeap newHeap;
  newHeap.Nodes = calloc(MAX, sizeof(Node));
  
  int x;
  for (x = MAX - 1; x >= 0; x--) {
    newHeap.Nodes[x].link = x - 1;
  }

  newHeap.Avail = MAX - 1;
  return newHeap;
}

// prints each element on a List in the format: [INDEX](DATA)->LINK
void displayList(VirtualHeap VH, List L) {
  int trav;
  for (trav = L; trav != -1; trav = VH.Nodes[trav].link) {
    printf("[%d](%c)->", trav, VH.Nodes[trav].data);
  }
  puts("-1");
}

// returns the index of an allocated Node form the VH->Avail List, otherwise -1 if it fails
int alloc(VirtualHeap *VH) {
  int toReturn = -1;
  
  if (VH->Avail != -1) {
    toReturn = VH->Avail;
    VH->Avail = VH->Nodes[VH->Avail].link;
  }

  return toReturn;
}

// deallocates a targetIndex and inserts it to the VH->Avail List
void dealloc(VirtualHeap *VH, int targetIndex) {
  VH->Nodes[targetIndex].link = VH->Avail;
  VH->Avail = targetIndex;
}

// allocates & inserts an elem on the first index of a List L
void insertFirst(VirtualHeap *VH, List *L, char elem) {
  int newNodeIndex = alloc(VH);

  if (newNodeIndex != -1) {
    VH->Nodes[newNodeIndex].data = elem;
    VH->Nodes[newNodeIndex].link = *L;
    *L = newNodeIndex;
  }
}

// sorts a List L on a VirtualHeap VH
void sortList(VirtualHeap *VH, List L) {
  int isSorted = 0;

  while (!isSorted) {
    int didSwap = 0, x;
    // stop at the node before the last one to compare forwards
    for (x = L; VH->Nodes[x].link != -1; x = VH->Nodes[x].link) {
      if (VH->Nodes[x].data > VH->Nodes[VH->Nodes[x].link].data) {
        char tmp = VH->Nodes[x].data;
        VH->Nodes[x].data = VH->Nodes[VH->Nodes[x].link].data;
        VH->Nodes[VH->Nodes[x].link].data = tmp;

        didSwap = 1; // raise swap flag, meaning list still not sorted
      }
    }

    // if we didn't swap in the entire traversal, then the list is sorted
    if (!didSwap) {
      isSorted = 1;
    }
  }
}

// clears a List by inserting first all of its elements to the VH->Avail List
void clearList(VirtualHeap *VH, List *L) {
  int trav = *L;
  while (trav != -1) {
    int tmp = trav;
    trav = VH->Nodes[trav].link;
    dealloc(VH, tmp);
  }

  *L = -1; // make L empty
}