#include <stdio.h>
#include <unistd.h> //sleep

#include "wheels.h"

int main(int argc, char *argv[]) {
    printf("Initialize wheels...\n");
    initWheels();
    printf("Move forward...\n");
    moveForward();
    printf("Sleep for 5 seconds...\n");
    sleep(5);
    printf("Stop...\n");
    stopWheels();
}
