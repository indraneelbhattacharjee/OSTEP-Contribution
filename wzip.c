#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    FILE *fp;
    int count = 0;
    char current, next;

    for (int i = 1; i < argc; i++) {
        fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("wzip: cannot open file\n");
            exit(1);
        }

        while (fread(&next, 1, 1, fp) == 1) {
            if (count == 0) {
                current = next;
                count++;
            } else if (next == current) {
                count++;
            } else {
                fwrite(&count, sizeof(int), 1, stdout);
                fwrite(&current, 1, 1, stdout);
                current = next;
                count = 1;
            }
        }

        fclose(fp);
    }

    if (count > 0) {
        fwrite(&count, sizeof(int), 1, stdout);
        fwrite(&current, 1, 1, stdout);
    }

    return 0;
}
