#include <stdio.h>
#define SIZE 5

void select(int arr[], int size);
void selectionSort(int arr[], int size);

int main(void)
{
    int arr[SIZE] = {9,8,7,6,5};
    selectionSort(arr, SIZE);
    printf("%d %d %d %d %d", arr[0], arr[1], arr[2], arr[3], arr[4]);
}

void selectionSort(int arr[], int size) {
    int CE;
    for (CE = 0; CE < size; CE++) {
        int T, SE = CE;
        // find the index of the Smallest Element
        for (T = CE + 1; T < size; T++) {
            if (arr[T] < arr[SE]) {
                SE = T;
            }
        }
        // if SE changed, swap the element
        if (SE != CE) {
            int tmp = arr[CE];
            arr[CE] = arr[SE];
            arr[SE] = tmp;
        }
    }
}

void select(int arr[], int size) {
    int x, SE = 0;
    // find the index of the SE element
    for (x = 1; x < size; x++) {
        if (arr[x] < arr[SE]) {
            SE = x;
        }
    }
    // if SE changed, swap the element
    if (SE != 0) {
        int tmp = arr[0];
        arr[0] = arr[SE];
        arr[SE] = tmp;
    }
}