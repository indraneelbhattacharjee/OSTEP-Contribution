#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char buffer[1024]; // Buffer to store each line read from file

    // Check if files are provided in the command line
    if (argc < 2) {
        exit(0); // No files specified, exit with status code 0
    }

    // Loop through each file provided in command line arguments
    for (int i = 1; i < argc; i++) {
        // Open the file
        fp = fopen(argv[i], "r");

        // Check if file opened successfully
        if (fp == NULL) {
            printf("wcat: cannot open file\n");
            exit(1);
        }

        // Read and print each line until end of file
        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            printf("%s", buffer);
        }

        // Close the file
        fclose(fp);
    }

    return 0;
}
