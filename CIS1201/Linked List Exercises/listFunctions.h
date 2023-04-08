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

/* helper functions */
void displayStudent(studrec rec);
void displayList(LIST head);
void pushNode(LIST head, studrec record);

/* exercise functions */
studrec findStudent(LIST head, const char *idToSearch);
studrec optimizedFindStudent(LIST head, const char *idToSearch);
void insertSorted(LIST head, studrec recordToInsert);
int deleteNodeByCourse(LIST head, const char *targetCourse);
int deleteAll(LIST head, const char *targetCourse);