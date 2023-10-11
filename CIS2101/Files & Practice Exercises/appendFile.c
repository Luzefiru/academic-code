#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char FN[24];
  char MI;
  char LN[16];
} Nametype;

typedef struct {
  Nametype name;
  int ID;
  char course[8];
  int yrLevel;
} Studtype;

void displayHeader();
void displayStudent(Studtype s);
void readAppendFile(void);

int main(void) {  
  readAppendFile();
}

/**
 * @brief This function writes at least 5 student records to the file whose name will be inputted by the user. 
 * 
 * @param arr 
 * @param fileToWriteTo 
 */
void readAppendFile(void) {
  Studtype s;
  printf("ID: ");
  scanf(" %d", &s.ID);
  printf("Last Name: ");
  scanf(" %s", &s.name.LN);
  printf("First Name: ");
  scanf(" %s", &s.name.FN);
  printf("Middle Initial: ");
  scanf(" %c", &s.name.MI);
  printf("Course: ");
  scanf(" %s", &s.course);
  printf("Year Level: ");
  scanf(" %d", &s.yrLevel);

  displayHeader();
  displayStudent(s);

  char fileToWriteTo[64];
  printf("Where do you want to append the record? ");
  scanf("%s", fileToWriteTo);

  FILE *fp = fopen(fileToWriteTo, "ab");
  if (fp == NULL) {
    fclose(fp);
    puts("Unexpected error");
    exit(EXIT_FAILURE);
  } else {
    fwrite(&s, sizeof(Studtype), 1, fp);
  }
  fclose(fp);
}


/**
 * @brief This function will display all the field members of the given Studtype record in 1 horizontal line. After every 20 records displayed, call the OS command “Pause” to halt/stop until any key is pressed in the keyboard.
 * 
 * @param s 
 */
void displayStudent(Studtype s) {
  printf("%-10d", s.ID);
  printf("%-16s", s.name.LN);
  printf("%-24s", s.name.FN);
  printf("%-3c", s.name.MI);
  printf("%-8s", s.course);
  printf("%5d", s.yrLevel);
  printf("\n");
}

/**
 * @brief This function will display the field titles such as ID, Lastnames, etc. This will be called once only and will be called before any call to displayStudent().
 * 
 */
void displayHeader() {
  printf("\n\n");
  printf("%-10s", "ID No.");
  printf("%-16s", "Lastname");
  printf("%-24s", "Firstname");
  printf("%-3s", "MI");
  printf("%-8s", "Course");
  printf("%5s", "Year");
  printf("\n");
  printf("%-10s", "======");
  printf("%-16s", "========");
  printf("%-24s", "=========");
  printf("%-3s", "==");
  printf("%-8s", "======");
  printf("%5s", "====");
  printf("\n");
}