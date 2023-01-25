// Diagnostic Activity

#include <stdio.h>
#include <stdlib.h>

/* BASIC TASKS */
int *inputData(void);
void displayArray(int arr[], int len);
int findElem(int arr[], int len, int target);

/* CHALLENGE */
void exchange(int *x, int *y);
int findSmallest(int arr[], int len);
void swapSmallestWithFirst(int arr[], int len);

/* ALGORITHM (my own work, not instructed) */
void selectionSort(int arr[], int len);

int main(void)
{
    puts("\nTASK 1"
         "\n------");
    int *arr = inputData();
    displayArray(arr+1, arr[0]);

    puts("\nTASK 2"
         "\n------");
    int x = 1;
    (findElem(arr+1, arr[0], x)) ? printf("%d is in the array.\n", x) : printf("%d is NOT in the array.\n", x);
    x = 123;
    (findElem(arr+1, arr[0], x)) ? printf("%d is in the array.\n", x) : printf("%d is NOT in the array.\n", x);

    puts("\nCHALLENGE"
         "\n---------");
    swapSmallestWithFirst(arr+1, arr[0]);
    displayArray(arr+1, arr[0]);

    puts("\nALGORITHM"
         "\n---------");
    selectionSort(arr+1, arr[0]);
    displayArray(arr+1, arr[0]);
}

/**
 * @brief an interface to initialize an array based on user input for size & individual elements
 * 
 * @return int* 
 */
int *inputData(void)
{
    int N;
    printf("Input the length of the array: ");
    scanf("%d", &N);

    int *arr = (int *) malloc((N+1) * sizeof(int));
    if (arr == NULL) exit(EXIT_FAILURE);

    arr[0] = N;
    int ind;
    for (ind = 1; ind <= N; ind++)
    {
        printf("Input element #%d: ", ind);
        scanf("%d", arr+ind);
    }

    return arr;
}

/**
 * @brief pretty prints the passed array
 * 
 * @param arr 
 * @param len 
 */
void displayArray(int arr[], int len)
{
    printf("Current array: ");

    int ind;
    putchar('[');
    for (ind = 0; ind < len; ind++)
        (ind < len-1) ? printf("%d, ", arr[ind]) : printf("%d", arr[ind]);
    puts("]");
}

/**
 * @brief returns 1 if {target} is in {arr}, otherwise returns 0
 * 
 * @param arr 
 * @param len 
 * @param target 
 * @return int 
 */
int findElem(int arr[], int len, int target)
{
    int ind;
    for (ind = 0; ind < len && arr[ind] != target; ind++) {}

    return (ind < len) ? 1 : 0;
}

/**
 * @brief exchanges the values of variables {x} & {y}
 * 
 * @param x 
 * @param y 
 */
void exchange(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

/**
 * @brief given an int array {arr} of length {len}, return the lowest value.
 * 
 * @param arr 
 * @param len 
 * @return int 
 */
int findSmallest(int arr[], int len)
{
    int ind, smallest = arr[0];
    for (ind = 1; ind < len; ind++)
        if (arr[ind] < smallest)
            smallest = arr[ind];

    return smallest;
        
}

/**
 * @brief swap the lowest value with the first element
 * 
 * @param arr 
 * @param len 
 */
void swapSmallestWithFirst(int arr[], int len)
{
    int ind, smallest = findSmallest(arr, len);
    for (ind = 0; ind < len; ind++)
        if (arr[ind] == smallest)
            exchange(arr+ind, arr);
}

/**
 * @brief performs the Selection Sort algorithm on the passed array
 * 
 * @param arr
 * @param len
 */
void selectionSort(int arr[], int len)
{
    int ind;
    for (ind = 0; ind < len; ind++)
        swapSmallestWithFirst(arr + ind, len - ind);
}
