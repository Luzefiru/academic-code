#include "listFunctions.h"

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

void displayList(LIST head) {
    struct node *currentNode;
    for (currentNode = head; currentNode != NULL; currentNode = currentNode->link) {
        displayStudent(currentNode->stud);
    }
    putchar('\n');
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
 * @brief Assuming the LIST is already sorted in ascending order, inserts a record to its sorted position based on ID
 * 
 * @param head - the {struct node} head
 * @param recordToInsert - the {studrec} to insert into the {LIST}
 */
void insertSorted(LIST head, studrec recordToInsert) {
    struct node *currentNode;
    struct node *previousNode;
    for (
        // start from the head & track the previous node
        currentNode = head, previousNode = NULL;
        // while the next node is not NULL && the current node's ID is less than the 
        currentNode->link != NULL && strcmp(currentNode->stud.ID, recordToInsert.ID) < 0; 
        // advance the current node
        previousNode = currentNode, currentNode = currentNode->link
    ) {}
    // stop when the currentNode's ID is greater than the recordToInsert
    // therefore, the previousNode should connect to the recordToInsert, which connects to currentNode

    // initialize a node to be inserted
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    if (previousNode == NULL) {
        newNode->stud = head->stud;
        newNode->link = head->link;

        head->link = newNode;
        head->stud = recordToInsert;
    } else {
        newNode->stud = recordToInsert;
        previousNode->link = newNode;
        newNode->link = currentNode;
    }
}