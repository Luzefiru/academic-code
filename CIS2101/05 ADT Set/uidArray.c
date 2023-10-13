#include <stdio.h>
#include <stdlib.h>

typedef int Set[10];

void displaySet(Set s);
Set *setUnion(Set S1, Set S2);
Set *setDifference(Set S1, Set S2);
Set *setIntersection(Set S1, Set S2);
Set *setXOR(Set S1, Set S2);

int main(void) {
  Set s1 = {1,1,0,0,0,0,1,1,0,1};
  Set s2 = {0,0,1,1,1,1,0,0,1,0};
  displaySet(*setUnion(s1, s2));
  displaySet(*setDifference(s1, s2));
  displaySet(*setIntersection(s1, s2));
  displaySet(*setXOR(s1, s2));
}

void displaySet(Set s) {
  int x;
  printf("{ ");
  for (x = 0; x < 10; x++) {
    printf("%d ", s[x]);
  }
  printf("}\n");
}

Set *setUnion(Set S1, Set S2) {
  Set *newSet = malloc(sizeof(Set));
  int x;
  for (x = 0; x < 10; x++) {
    (*newSet)[x] = S1[x] | S2[x];
  }
  return newSet;
}

Set *setIntersection(Set S1, Set S2) {
  Set *newSet = malloc(sizeof(Set));
  int x;
  for (x = 0; x < 10; x++) {
    (*newSet)[x] = S1[x] & S2[x];
  }
  return newSet;
}

Set *setDifference(Set S1, Set S2) {
  Set *newSet = malloc(sizeof(Set));
  int x;
  for (x = 0; x < 10; x++) {
    (*newSet)[x] = S1[x] & ~S2[x];
  }
  return newSet;
}

Set *setXOR(Set S1, Set S2) {
  Set *newSet = malloc(sizeof(Set));
  int x;
  for (x = 0; x < 10; x++) {
    (*newSet)[x] = S1[x] ^ S2[x];
  }
  return newSet;
}