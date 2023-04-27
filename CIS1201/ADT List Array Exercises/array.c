#include <stdio.h>
#include <stdlib.h>

#include "array.h"

void display(List L) {
    printf("[");
    int i;
    for (i = 0; i < L.count; i++) {
        (i < L.count-1) ? printf("%d, ", L.elem[i]) : printf("%d]\n", L.elem[i]);
    }
}

/**
 * @brief adds an element to the end of the List
 * 
 * @param L {List *} a pointer to the List
 * @param e {int} the element to add
 */
void push(List *L, int e) {
    if (L->count < MAX_SIZE) {
        L->elem[L->count++] = e;
    } else {
        puts("ERR: Array full.");
    }
}

/**
 * @brief removes an element at the end of the list and returns it
 * 
 * @param L {List *} a pointer to the List
 * @return {int} the popped element
 */
int pop(List *L) {
    if (L->count > 0) {
        return L->elem[L->count-- -1];
    } else {
        puts("ERR: Array already empty.");
    }
}

/**
 * @brief adds an element to the start of the List, shifting every element to the right
 * 
 * @param L {List *}
 * @param e {int} to element to add
 */
void unshift(List *L, int e) {
    if (L->count < MAX_SIZE) {
        int x;
        // shift all elements to the right, starting from the end, making x to be 0
        for (x = L->count; x > 0; x--) {
            L->elem[x] = L->elem[x-1];
        }
        // assign the new element to the starting index
        L->elem[x] = e;
        // increment List's count
        L->count++;
    } else {
        puts("ERR: Array is full.");
    }
}

/**
 * @brief removes the element at the starting index then returns it
 * 
 * @param L {List *}
 * @return {int} the removed element
 */
int shift(List *L) {
    if (L->count > 0) {
         // return the first element later
        int retval = L->elem[0];

        // shift everything to the left, starting from the starting index
        int x;
        for (x = 0; x < L->count; x++) {
            L->elem[x] = L->elem[x+1];
        }

        // decrement count
        L->count--;

        return retval;
    } else {
        puts("ERR: Array is empty.");
    }
}

/**
 * @brief sorts the List in descending order (greatest -> least)
 * 
 * Uses Bubble Sort
 * 
 * @param L {List *}
 */
void sortDescending(List *L) {
    int x, y;
    for (x = 1; x < L->count; x++) {
        for (y = 0; y < L->count - x; y++) {
            if (L->elem[y] < L->elem[y+1]) {
                // swap the elements if the current is less than the next
                int tmp = L->elem[y];
                L->elem[y] = L->elem[y+1];
                L->elem[y+1] = tmp;
            }
        }
    }
}

/**
 * @brief sorts the List in ascending order (least -> greatest)
 * 
 * It's the same as above, but the only code we change is the comparison conditional statement
 * 
 * @param L {List *}
 */
void sortAscending(List *L) {
    int x, y;
    for (x = 1; x < L->count; x++) {
        for (y = 0; y < L->count - x; y++) {
            if (L->elem[y] > L->elem[y+1]) { // notice how we only changed the comparison operator
                int tmp = L->elem[y];
                L->elem[y] = L->elem[y+1];
                L->elem[y+1] = tmp;
            }
        }
    }
}