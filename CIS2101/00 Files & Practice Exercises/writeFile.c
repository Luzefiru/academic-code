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
void writeFile(const Studtype *arr, const char *fileToWriteTo);

int main(void) {
  Nametype person1 = {"John", 'D', "Smith"};
  Studtype student1 = {person1, 101, "BSCS", 1};
  Nametype person2 = {"Sarah", 'M', "Johnson"};
  Studtype student2 = {person2, 202, "BSEE", 3};
  Nametype person3 = {"Michael", 'S', "Brown"};
  Studtype student3 = {person3, 303, "BSAP", 2};
  Nametype person4 = {"Emily", 'K', "Davis"};
  Studtype student4 = {person4, 404, "BSAM", 4};
  Nametype person5 = {"Olivia", 'R', "Garcia"};
  Studtype student5 = {person5, 505, "BSCHE", 1};

  Studtype arr[5] = {student1, student2, student3, student4, student5};
  
  writeFile(arr, "test.dat");
}

/**
 * @brief This function writes at least 5 student records to the file whose name will be inputted by the user. 
 * 
 * @param arr 
 * @param fileToWriteTo 
 */
void writeFile(const Studtype *arr, const char *fileToWriteTo) {
  FILE *fp = fopen(fileToWriteTo, "wb");
  if (fp == NULL) {
    fclose(fp);
    puts("Unexpected error");
    exit(EXIT_FAILURE);
  } else {
    int x;
    for (x = 0; x < 5; x++) {
      displayHeader();
      displayStudent(arr[x]);
      fwrite(&arr[x], sizeof(Studtype), 1, fp);
    }
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