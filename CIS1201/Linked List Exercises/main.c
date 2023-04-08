#include "listFunctions.h"

int main(void)
{
    
    

    /* setup */
    studrec rec1 = {"001", {"Christian", "de Jesus", 'L'}, "BSCS", 1};
    studrec rec2 = {"002", {"John", "Doe", 'D'}, "BSCS", 2};
    studrec rec3 = {"004", {"Juan", "de La Cruz", 'L'}, "BSIT", 3};

    struct node *startNode = (struct node*)malloc(sizeof (struct node));
    startNode->link = NULL;
    startNode->stud = rec1;
    LIST head = startNode; // pointer to a struct node

    pushNode(head, rec2);
    pushNode(head, rec3);
    
    printf("displayList(head);\n");
    displayList(head);
    
    // /* Exercise 1 */
    printf("findStudent(head, \"001\");\n>>> "); displayStudent(findStudent(head, "001"));
    putchar('\n');
    printf("findStudent(head, \"004\");\n>>> "); displayStudent(findStudent(head, "004"));
    putchar('\n');
    printf("findStudent(head, \"I DON'T EXIST\");\n>>> "); displayStudent(findStudent(head, "I DON'T EXIST")); putchar('\n');

    // /* Exercise 2 */
    studrec start = {"000", {"Genesis", "Manson", 'G'}, "BSCS", 2};
    studrec middle = {"003", {"Thirdie", "McQueen", 'D'}, "BSIT", 4};
    studrec end = {"999", {"Endie", "Enderman", 'E'}, "BSIT", 1};
    insertSorted(head, start);
    insertSorted(head, middle);
    insertSorted(head, end);
    printf("insertSorted(head, start);\n");
    printf("insertSorted(head, middle);\n");
    printf("insertSorted(head, end);\n");
    displayList(head);

    /* Exercise 3 */
    printf("deleteAll(head, \"BSCS\");\n");
    deleteAll(head, "BSCS");
    displayList(head);
    printf("deleteAll(head, \"BSIT\");\n");
    deleteAll(head, "BSIT");
    displayList(head);
}

