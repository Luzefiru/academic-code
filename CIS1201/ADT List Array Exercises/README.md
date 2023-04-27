# File Structure

1. `main.c` - the main program.
2. `array.h` - the interface module containing data models & function definitions.
3. `array.c` - source code containing the function definitions of the interface.

# Running `make.sh`

You need to allow the file to be executable via the `chmod` command in Unix.

```bash
# enable the execution bit on the current user
chmod make.sh u+x
```

You should get a `main.exe` file you can then execute with:

```bash
./make
```

# Contents

```C
#define MAX_SIZE 10

typedef struct {
    int elem[MAX_SIZE];
    int count;
} List;

void display(List L);
void push(List *L, int e);
int pop(List *L);
void unshift(List *L, int e);
int shift(List *L);
void sortDescending(List *L);
void sortAscending(List *L);
```
