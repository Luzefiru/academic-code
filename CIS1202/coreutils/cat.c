#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // displays utility usage on `cat --help`
    if (strcmp(argv[1], "--help") == 0) {
        fprintf(stdout, 
            "Usage: cat [FILE]\n"
            "Concatenates FILE to stdout.\n\n"
            "%12s%32s",
            "--help",
            "display this help and exit"
        );
        exit(EXIT_SUCCESS);
    }

    // opens the first argument passed into the CLI program as a file
    FILE *fp = fopen(argv[1], "r");

    // handles any file pointer errors
    if (fp == NULL) {
        fprintf(stderr, "cat: %s: No such file or directory", argv[1]);
    }

    // happy path
    char ch;
    while ((ch = getc(fp)) != EOF) {
        fputc(ch, stdout);
    }
}
