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

studrec findStudent(LIST head, const char *idToSearch);
studrec optimizedFindStudent(LIST head, const char *idToSearch);
void displayStudent(studrec rec);