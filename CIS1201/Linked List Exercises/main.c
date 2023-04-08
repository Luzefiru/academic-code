#include "listFunctions.h"

studrec findStudent(LIST head, const char *idToSearch);
studrec optimizedFindStudent(LIST head, const char *idToSearch);
void displayStudent(studrec rec);

int main(void)
{
    /* setup */
    studrec rec1 = {"22101295", {"Christian", "de Jesus", 'L'}, "BSCS", 1};
    studrec rec2 = {"22101001", {"John", "Doe", 'D'}, "BSCS", 2};
    studrec rec3 = {"22101512", {"Juan", "de La Cruz", 'L'}, "BSCS", 3};

    struct node node3 = {rec3, NULL};
    struct node node2 = {rec2, &node3};
    struct node node1 = {rec1, &node2};

    LIST head = &node1; // pointer to a struct node
    
    printf(
        "*****************\n"
        "* Available IDs *\n"
        "*****************\n"
        "*   %s    *\n"
        "*   %s    *\n"
        "*   %s    *\n"
        "*****************\n\n",
        head->stud.ID, head->link->stud.ID, head->link->link->stud.ID
    );
    
    /* function calls */
    printf("findStudent(head, \"22101295\");\n>>> "); displayStudent(findStudent(head, "22101295"));
    putchar('\n');
    printf("findStudent(head, \"22101512\");\n>>> "); displayStudent(findStudent(head, "22101512"));
    putchar('\n');
    printf("findStudent(head, \"I DON'T EXIST\");\n>>> "); displayStudent(findStudent(head, "I DON'T EXIST"));
}

