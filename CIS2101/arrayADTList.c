#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
  int elem[MAX];
  int count;
} ArrayList;

void printArray(ArrayList list);
void insertUniqueLast(ArrayList *list, int elem);
void deleteAtIndex(ArrayList *list, int index);
void deleteTarget(ArrayList *list, int target);
void deleteAllTargets(ArrayList *list, int target);
void push(ArrayList *list, int elem);
int pop(ArrayList *list);
int shift(ArrayList *list);
void unshift(ArrayList *list, int newElem);
int sumArray(ArrayList *list);
double averageArray(ArrayList *list);
int findMax(ArrayList *list);
int findMin(ArrayList *list);
_Bool existsInArray(ArrayList *list, int elem);
int getIndex(ArrayList *list, int elem);
void bubbleSort(ArrayList *list);
_Bool isSorted(ArrayList *list);

int main(void) {
  ArrayList list = { {2,1,-9}, .count = 3 };
  printArray(list);
  bubbleSort(&list);
  printArray(list);
  printf("%d", isSorted(&list));
}

void printArray(ArrayList list) {
  int x;
  putchar('[');
  for (x = 0; x < list.count; x++) {
    (x != list.count - 1) ? printf("%d, ", list.elem[x]) : printf("%d", list.elem[x]);
  }
  puts("]");
}

// inserts the elem to the last index if there are no elements that match elem in the array already
void insertUniqueLast(ArrayList *list, int elem) {
  if (list->count < MAX) {
    int x;
    // while we do not reach the list count & the current element doesn't match {elem}
    for (x = 0; x < list->count && list->elem[x] != elem; x++) {}
    // if x late early and elem never matched while traversing the loop, insert
    if (x == list->count) {
      list->elem[x] = elem;
      list->count++;
    }
  }
}

// deletes the array element in index
void deleteAtIndex(ArrayList *list, int index) {
  if (list->count != 0 && index >= 0 && index < list->count) {
    int x;
    for (x = index; x < list->count; x++) {
      list->elem[x] = list->elem[x + 1]; // shift all elements from right to left, covering index
    }
    list->count--;
  }
}

void deleteTarget(ArrayList *list, int target) {
  if (list->count > 0) {
    int x;
    for (x = 0; x < list->count && list->elem[x] != target; x++) {} // we stop at target's index
    for (; x < list->count; x++) {
      list->elem[x] = list->elem[x + 1]; // shift all elements to the left
    }
    list->count--;
  }
}

// deletes all instances of elem in the array
void deleteAllTargets(ArrayList *list, int target) {
  if (list->count > 0) {
    int x;
    for (x = 0; x < list->count; x++) {
      if (list->elem[x] == target) {
        int y;
        for (y = x; y < list->count; y++) {
          list->elem[y] = list->elem[y + 1];
        }
        list->count--;
        x--;
      }
    }
  }
}

// inserts elem to the end of the array
void push(ArrayList *list, int elem) {
  if (list->count < MAX) {
    list->elem[list->count++] = elem;
  }
}

// removes the last element & returns it, otherwise -1 if it fails
int pop(ArrayList *list) {
  int retval = -1;

  if (list->count > 0) {
    retval = list->elem[list->count-1];
    list->count--;
  }
  
  return retval;
}

// removes the first element & returns it, otherwise -1 if fail
int shift(ArrayList *list) {
  int retval = -1;

  if (list->count > 0) {
    int x;
    for (x = 0; x < list->count -1; x++) {
      list->elem[x] = list->elem[x + 1];
    }
    list->count--;
  }

  return retval;
}

// adds an newElem to the beginning of the array
void unshift(ArrayList *list, int newElem) {
  if (list->count < MAX) {
    int x;
    for (x = list->count; x > 0; x--) {
      list->elem[x] = list->elem[x-1];
    }
    list->elem[0] = newElem;
    list->count++;
  }
}

// sums the elements of the array and returns it
int sumArray(ArrayList *list) {
  int x, sum = 0;
  for (x = 0; x < list->count; x++) {
    sum += list->elem[x];
  }
  return sum;
}

// finds the average of the elements in the array
double averageArray(ArrayList *list) {
  int x, sum = 0;
  for (x = 0; x < list->count; x++) {
    sum += list->elem[x];
  }
  return (double) sum / list->count;
}

// finds the element with the largest value, otherwise -1 if it fails
int findMax(ArrayList *list) {
  int max = -1;

  if (list->count > 0) {
    int x;
    max = list->elem[0];

    for (x = 1; x < list->count; x++) {
      if (list->elem[x] > max) {
        max = list->elem[x];
      }
    }
  }

  return max;
}

// finds the element with the lowest value, otherwise -1 if it fails
int findMin(ArrayList *list) {
  int min = -1;

  if (list->count > 0) {
    min = list->elem[0];
    int x;
    for (x = 0; x < list->count; x++) {
      if (list->elem[x] < min) {
        min = list->elem[x];
      }
    }
  }

  return min;
}

// checks if elem exists in the list
_Bool existsInArray(ArrayList *list, int elem) {
  int x;
  for (x = 0; x < list->count && elem != list->elem[x]; x++) {}
  return (x == list->count) ? 0 : 1;
}

// returns the index of elem in list, returns -1 if it doesn't exist
int getIndex(ArrayList *list, int elem) {
  int x;
  for (x = 0; x < list->count && list->elem[x] != elem; x++) {}
  return (x == list->count) ? -1 : x;
}

// sorts the array with bubble sort
void bubbleSort(ArrayList *list) {
  int x, y;
  for (x = 0; x < list->count; x++) {
    for (y = 0; y < list->count - x; y++) {
      if (list->elem[y] > list->elem[y+1]) {
        int tmp = list->elem[y];
        list->elem[y] = list->elem[y+1];
        list->elem[y+1] = tmp;
      }
    }
  }
}

_Bool isSorted(ArrayList *list) {
  int x;
  for (x = 0; x < list->count-1 && list->elem[x] < list->elem[x+1]; x++) {}
  return (x == list->count-1) ? 1 : 0;
}