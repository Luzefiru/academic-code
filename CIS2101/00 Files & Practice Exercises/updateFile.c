#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void updateFile(const char *oldCourse, const char *newCourse);

int main(void) {
  const char *oldCourse = "BSCS", *newCourse = "HAHA";
  
  updateFile(oldCourse, newCourse);
}

/**
 * @brief Given an old course and new course as parameters, the function will read the contents of a file 1 record at a time and whose name will be inputted by the user. 
 * 
 */
void updateFile(const char *oldCourse, const char *newCourse) {
  const char *fileNameToUpdate = "test.dat";
  
  FILE *fp = fopen(fileNameToUpdate, "rb");
  FILE *newFile = fopen("placeholder.dat", "wb");

  if (fp == NULL || newFile == NULL) {
    printf("Unexpected error");
    fclose(fp); 
    fclose(newFile);
    exit(EXIT_FAILURE);
  } else {
    Studtype buffer;
    // read all data into another file with newCourse
    while (fread(&buffer, sizeof(Studtype), 1, fp) != 0) {
        if (strcmp(oldCourse, buffer.course) == 0) {
          strcpy(buffer.course, newCourse);
        }

        fwrite(&buffer, sizeof(Studtype), 1, newFile);
    }

    // close file pointers
    fclose(fp);
    fclose(newFile);

    // delete old file * rename new file to old file's name
    remove(fileNameToUpdate);
    rename("placeholder.dat", fileNameToUpdate);
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
  printf("\n");
}