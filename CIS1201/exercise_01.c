#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   char FN[24], LN[16], MI; // first name, last name, middle initial
} Nametype;

typedef struct {
   char ID[10];
   Nametype name;
   char course[8];
   int yearLevel;
} studrec;

typedef struct node {
    studrec stud;
    struct node *link;
} *LIST; // Definition of the list


/* 
Exercise Specifications:

Write the code of the function findStudent().
Given a list and an ID, the function will find the student record bearing the given ID an return the student record to the calling function.
If the student record does not exist, return a dummy record whose ID field contains "XXXXXX".

Note: Function should have 1 return statement ONLY, no break or exit statement.
*/

studrec findStudent(LIST head, const char *idToSearch);
studrec optimizedFindStudent(LIST head, const char *idToSearch);
void displayStudent(studrec rec); // helper function

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

/**
 * @brief Attempts to match & return a {studrec} with a corresponding {idToSearch}.
 * 
 * @param head - a pointer to the struct node's start
 * @param idToSearch - the ID to match
 * @return studrec - the studrec with the matching ID, otherwise a dummy record with "XXXXXX" as the studrec.ID
 */
studrec findStudent(LIST head, const char *idToSearch)
{
    // dummy record to be returned if no match is found,
    // otherwise gets reassigned to the record that corresponds to {idToSearch}
    studrec returnValue = {"XXXXXX", {"XXX", "XXX", 'X'}, "XXXX", 0};

    struct node *currentNode;
    for (currentNode = head; strcmp(returnValue.ID, idToSearch) && currentNode != NULL; currentNode = currentNode->link) {
        // if the currentNode's ID matches {idToSearch}
        if (strcmp(currentNode->stud.ID, idToSearch) == 0) {
            // copy the {currentNode}'s studrec to the {returnValue}
            returnValue = currentNode->stud;
        }
    }

    return returnValue;
}

/**
 * @brief Attempts to match & return a {studrec} with a corresponding {idToSearch}.
 * 
 * @param head - a pointer to the struct node's start
 * @param idToSearch - the ID to match
 * @return studrec - the studrec with the matching ID, otherwise a dummy record with "XXXXXX" as the studrec.ID
 */
studrec optimizedFindStudent(LIST head, const char *idToSearch)
{
    // dummy record to be returned if no match is found,
    // otherwise gets reassigned to the record that corresponds to {idToSearch}
    studrec returnValue = {"XXXXXX", {"XXX", "XXX", 'X'}, "XXXX", 0};

    // traverse through the {LIST} with a pointer to the current struct node {currentNode} until it's NULL (end of list)
    // first condition always evaluates to either != 0 if they do not match,
    // once they do, it evaluates to false, exiting the loop early for optimization.
    for (struct node *currentNode = head; strcmp(returnValue.ID, idToSearch) && currentNode != NULL; currentNode = currentNode->link) {
        // if the currentNode's ID matches {idToSearch}
        if (strcmp(currentNode->stud.ID, idToSearch) == 0) {
            // copy the {currentNode}'s studrec to the {returnValue}
            returnValue = currentNode->stud;
        }
    }

    return returnValue;
}

/**
 * @brief A helper function that pretty prints a {studrec}.
 * 
 * Very fun color escape codes were from here:
 * https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
 * I always wanted to know how those CLI tools create colored output, and now I do!
 * 
 * @param rec - the student record to display
 */
void displayStudent(studrec rec)
{
    #define ANSI_COLOR_RED     "\x1b[31m"
    #define ANSI_COLOR_GREEN   "\x1b[32m"
    #define ANSI_COLOR_RESET   "\x1b[0m"

    // change the stdout color according to whether the studrec is not dummy data
    if (strcmp(rec.ID, "XXXXXX") == 0) {
        printf(ANSI_COLOR_RED);
    } else {
        printf(ANSI_COLOR_GREEN);
    }

    printf("{\"%s\", {\"%s\", \"%s\", '%c'}, \"%s\", %d}\n",
        rec.ID, rec.name.FN, rec.name.LN, rec.name.MI, rec.course, rec.yearLevel);

    // reset the stdout color back to normal
    printf(ANSI_COLOR_RESET);
}
