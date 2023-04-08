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

void pushNode(LIST head, studrec record) {
    struct node *currentNode;
    for (currentNode = head; currentNode->link != NULL; currentNode = currentNode->link) {}

    struct node *newNode = (struct node *)malloc(sizeof (struct node));
    newNode->stud = record;
    newNode->link = NULL;

    currentNode->link = newNode;
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
        // while the currentNode is not NULL && the current node's ID is less than the 
        currentNode != NULL && strcmp(currentNode->stud.ID, recordToInsert.ID) < 0; 
        // advance the current node
        previousNode = currentNode, currentNode = currentNode->link
    ) {}
    // stop when the currentNode's ID is greater than the recordToInsert
    // therefore, the previousNode should connect to the recordToInsert, which connects to currentNode

    // initialize a node to be inserted
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    // handle unshifting elements to the starting node
    if (previousNode == NULL) {
        // make the newNode become head
        newNode->stud = head->stud;
        newNode->link = head->link;
        // make head become the recordToInsert, pointing to the old head, newNode
        head->link = newNode;
        head->stud = recordToInsert;
    } else {
        newNode->stud = recordToInsert;
        previousNode->link = newNode;
        newNode->link = currentNode;
    }
}

/**
 * @brief Deletes the first node with {targetCourse}
 * 
 * @return int - 1 if a deletion occured, otherwise 0
 */
int deleteNodeByCourse(LIST head, const char *targetCourse) {
    int successFlag = 0;
    
    struct node *prev;
    struct node *cur;
    for (cur = head, prev = NULL; !successFlag && cur != NULL; prev = cur, cur = cur->link) {
        if (strcmp(cur->stud.course, targetCourse) == 0) {
            if (prev == NULL && cur->link == NULL) {
                // catcher for a singleton element in the list
                head->stud = (studrec){"XXXXXX", {"XXX", "XXX", 'X'}, "XXXX", 0};
            } else if (prev == NULL) {
                // catcher for unshifting starting element
                struct node *toBeDeleted = head->link;

                head->stud = head->link->stud;
                head->link = head->link->link;

                free(toBeDeleted);
                successFlag = 1;
            } else {
                // delete the middle or end element
                prev->link = cur->link;
                free(cur);
                successFlag = 1;
            }
        }
    }
    return successFlag;
}

/**
 * @brief Deletes all nodes with {targetCourse}
 * 
 * @param head - the start of the list of {studrec}
 * @param targetCourse - the course string to be used as a reference for deleting nodes
 * @return int - the number of nodes deleted
 */
int deleteAll(LIST head, const char *targetCourse) {
    int nodesDeleted = 0;

    // keep deleting nodes until failure
    while (deleteNodeByCourse(head, targetCourse)) {
        nodesDeleted++;
    }

    return nodesDeleted;
}