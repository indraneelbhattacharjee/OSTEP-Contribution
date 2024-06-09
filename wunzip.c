#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    FILE *fp;
    int count;
    char character;

    for (int i = 1; i < argc; i++) {
        fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("wunzip: cannot open file\n");
            exit(1);
        }

        while (fread(&count, sizeof(count), 1, fp) == 1) {
            fread(&character, sizeof(character), 1, fp);
            for (int j = 0; j < count; j++) {
                printf("%c", character);
            }
        }

        fclose(fp);
    }

    return 0;
}
