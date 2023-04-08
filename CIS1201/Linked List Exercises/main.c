#include "listFunctions.h"

int main(void)
{
    /* setup */
    studrec rec1 = {"001", {"Christian", "de Jesus", 'L'}, "BSCS", 1};
    studrec rec2 = {"002", {"John", "Doe", 'D'}, "BSCS", 2};
    studrec rec3 = {"004", {"Juan", "de La Cruz", 'L'}, "BSCS", 3};

    struct node node3 = {rec3, NULL};
    struct node node2 = {rec2, &node3};
    struct node node1 = {rec1, &node2};

    LIST head = &node1; // pointer to a struct node

    displayList(head);
    
    // /* Exercise 1 */
    // printf("findStudent(head, \"001\");\n>>> "); displayStudent(findStudent(head, "001"));
    // putchar('\n');
    // printf("findStudent(head, \"004\");\n>>> "); displayStudent(findStudent(head, "004"));
    // putchar('\n');
    // printf("findStudent(head, \"I DON'T EXIST\");\n>>> "); displayStudent(findStudent(head, "I DON'T EXIST"));

    /* Exercise 2 */
    studrec rec4 = {"003", {"Thirdie", "McQueen", 'D'}, "BSCS", 4};
    insertSorted(head, rec4);
    displayList(head);
}

