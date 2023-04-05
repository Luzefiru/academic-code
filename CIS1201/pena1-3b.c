#include <stdio.h>

void findLEAndSwapWith0(char str[]);

int main(void)
{
    char str[] = "zacde"; 
    findLEAndSwapWith0(str);
    printf("%c %c %c %c %c", str[0], str[1], str[2], str[3], str[4]);
}

void findLEAndSwapWith0(char str[]) {
    int LE = 0, T;
    for (int T = 1; str[T] != '\0'; T++) {
        if (str[T] < str[LE]) {
            LE = T;
        }
    }
    if (LE != 0) {
        char tmp = str[0];
        str[0] = str[LE];
        str[LE] = tmp;
    }
}
