#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/* color codes - FOR DEBUGGING ONLY */
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_RESET   "\x1b[0m"
void prettyPrint(const char *str);

int main(void) {
    List arr = {{1,2,3}, 3};

    /* essentials */
    prettyPrint(">>> display: Should be [1, 2, 3]");
    display(arr);

    prettyPrint(">>> push: Should be [1, 2, 3, 9]");
    push(&arr, 9);
    display(arr);

    prettyPrint(">>> pop: Should be 9 [1, 2, 3]");
    printf("%d\n", pop(&arr));
    display(arr);

    prettyPrint(">>> unshift: Should be [9, 1, 2, 3]");
    unshift(&arr, 9);
    display(arr);

    prettyPrint(">>> shift: Should be 9 [1, 2, 3]");
    printf("%d\n", shift(&arr));
    display(arr);

    /* sorting */
    prettyPrint(">>> sortDescending: Should be [3, 2, 1]");
    sortDescending(&arr);
    display(arr);

    prettyPrint(">>> sortAscending: Should be [1, 2, 3]");
    sortAscending(&arr);
    display(arr);

    /* debug */
    printf("\nPress any key to continue...");
    getchar(); // blocker to see output
}

/**
 * @brief pretty prints a string with a magenta color if the system is Unix-based
 * 
 * @param str {const char *} the string to print
 */
void prettyPrint(const char *str) {
    #ifdef __linux__
    printf(ANSI_COLOR_MAGENTA);
    printf("\n%s\n", str);
    printf(ANSI_COLOR_RESET);
    #elif __APPLE__
    printf(ANSI_COLOR_MAGENTA);
    printf("\n%s\n", str);
    printf(ANSI_COLOR_RESET);
    #else
    printf("\n%s\n", str);
    #endif
}

