#include <stdio.h>
#include <stdlib.h>

void write_to_file(char *path, char *content) {
    FILE *filePointer;

    filePointer = fopen(path, "w");

    if(filePointer == NULL) {
        printf("Error!");   
        exit(1);             
    }

    fprintf(filePointer, "%s", content);
    fclose(filePointer);
}
