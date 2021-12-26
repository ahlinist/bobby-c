#include <stdio.h>
#include <stdlib.h>

void writeToFile(char *path, char *content) {
    FILE *filePointer;

    filePointer = fopen(path, "w");

    if(filePointer == NULL) {
        printf("Error!");   
        exit(1);             
    }

    fprintf(filePointer, "%s", content);
    fclose(filePointer);
}
