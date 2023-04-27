#define MAX_SIZE 10

typedef struct {
    int elem[MAX_SIZE];
    int count;
} List;

/* essentials */
void display(List L);
void push(List *L, int e);
int pop(List *L);
void unshift(List *L, int e);
int shift(List *L);
/* sorting */
void sortDescending(List *L);
void sortAscending(List *L);