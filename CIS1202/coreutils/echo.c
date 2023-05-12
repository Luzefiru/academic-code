#include <stdio.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        fputs(argv[i], stdout);
        fputc(' ', stdout);
    }
    fputs("\n\n", stdout);
}