#include <stdio.h>
#include <math.h>

typedef char Set;
typedef enum { TRUE, FALSE } boolean;

void printBitPattern(char ch);
boolean isMember(Set S, int elem);
void insert(Set *S, int elem);
void delete(Set *S, int elem);

int main(void) {
  Set s = 'a';
  printBitPattern(s);
  printf("%d\n", isMember(s, 5));
  insert(&s, 1);
  delete(&s, 0);
  printBitPattern(s);
}

// 1
void printBitPattern(char ch) {
  int offset = sizeof(ch) * 8 - 1;

  for (; offset >= 0; offset -= 1) {
    printf("%d", ch >> offset & 1);
  }
  puts("");
}

// 2
boolean isMember(Set S, int elem) {
  return S >> elem & 1 == 1;
}

void insert(Set *S, int elem) {
  *S = *S | 1 << elem;
}

void delete(Set *S, int elem) {
  *S = *S & ~(1 << elem);
}