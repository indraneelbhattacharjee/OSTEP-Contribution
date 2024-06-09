#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Check if the search term is provided
    if (argc < 2) {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    char *search_term = argv[1];

    // Check if any files are provided
    if (argc == 2) {
        // Search from standard input
        char line[BUFFER_SIZE];
        while (fgets(line, BUFFER_SIZE, stdin) != NULL) {
            if (strstr(line, search_term) != NULL) {
                printf("%s", line);
            }
        }
    } else {
        // Search through each file provided
        for (int i = 2; i < argc; i++) {
            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL) {
                printf("wgrep: cannot open file\n");
                exit(1);
            }

            char line[BUFFER_SIZE];
            while (fgets(line, BUFFER_SIZE, fp) != NULL) {
                if (strstr(line, search_term) != NULL) {
                    printf("%s", line);
                }
            }

            fclose(fp);
        }
    }

    return 0;
}
