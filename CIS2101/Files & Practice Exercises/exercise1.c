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
void readFile();

int main(void) {
  // Nametype fn = {"Ian", 'L', "de Jesus"};
  // Studtype ian = {fn, 123, "BSCS", 2};
  // displayStudent(ian);

  char fileToRead[64];

  printf("Enter a file name : ");
  scanf("%s", &fileToRead);

  displayHeader();

  readFile(fileToRead);
}

/**
 * @brief This function reads the student records in the given file 1 record at a time and calls displayStudent() to display all the fields in the given record. Note that the name of the file will be inputted by the user from the keyboard.
 * 
 */
void readFile(const char *fileToRead) {
  FILE *fp = fopen(fileToRead, "rb");

  if (fp == NULL) {
    fclose(fp);
    printf("\n'%s' does not exist", fileToRead);
  } else {
    Studtype current;
    int count = 0;
    while (fread(&current, sizeof(Studtype), 1, fp) != 0) {
      printf("%d", current.ID);
      displayStudent(current);
      count++;

      if (count % 20 == 0) {
        printf("\nPress any key to continue...\n");
        fflush(stdin);
        getchar();
      }
    }
  }

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
}