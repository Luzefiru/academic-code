#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
  char Elements[SIZE];
  char count;
} List1;

typedef List1 * List2;

typedef struct {
  char *elemPtr;
  char count;
} List3;

typedef List3 * List4;

List2 initializeList2(void);
List3 initializeList3(void);
List4 initializeList4(void);

int main(void) {

}

List2 initializeList2(void) {
  List2 newList = (List1 *)malloc(sizeof(List1));
  newList->count = 0;
  return newList;
}

List3 initializeList3(void) {
  List3 newList;
  newList.elemPtr = (char *)malloc(sizeof(char) * SIZE);
  newList.count = 0;
  return newList;
}

List4 initializeList4(void) {
  List3 *listData;
  listData->elemPtr = (char *)malloc(sizeof(char) * SIZE);
  listData->count = 0;
  List4 newList = listData;

  return newList;
}