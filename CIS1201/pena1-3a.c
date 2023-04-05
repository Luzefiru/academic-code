#include <stdio.h>
#define SIZE 5

void findSmallestAndSwapWith0(int arr[], int size);

int main(void)
{
    int arr[SIZE] = {4,5,2,1,7};
    findSmallestAndSwapWith0(arr, SIZE);
    printf("%d %d %d %d %d", arr[0], arr[1], arr[2], arr[3], arr[4]);
}

void findSmallestAndSwapWith0(int arr[], int size) {
    int x, smallest = 0;
    // find the index of the smallest element
    for (x = 1; x < size; x++) {
        if (arr[x] < arr[smallest]) {
            smallest = x;
        }
    }
    // if smallest changed, swap the element
    if (smallest != 0) {
        int tmp = arr[0];
        arr[0] = arr[smallest];
        arr[smallest] = tmp;
    }
}