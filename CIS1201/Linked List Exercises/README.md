# File Structure

1. `main.c` - the main program.
2. `listFunctions.h` - the interface module containing data models & function definitions.
3. `lsitFunctions.c` - source code containing the function definitions of the interface.

# Running `make.sh`

You need to allow the file to be executable via the `chmod` command in Unix. Otherwise, you can just use the `sh` command in Windows to run it.

```bash
# enable the execution bit on the current user
chmod make.sh u+x

# run the pseudo makefile
./make.sh

# for Windows users
sh make.sh
```

You should get a `main.exe` file you can then execute with:

```bash
./make
```

# Practice Specifications

`findStudent()`

> Write the code of the function findStudent().
> Given a list and an ID, the function will find the student record bearing the given ID an return the student record to the calling function.
> If the student record does not exist, return a dummy record whose ID field contains "XXXXXX".
> Note: Function should have 1 return statement ONLY, no break or exit statement.

`insertSorted()`

> Given a SORTED list and a student record, the function will insert the student record at its appropriate position in the list which is sorted in ascending order according to ID.
> Note: There should be No break or exit statement.
