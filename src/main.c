#include <stdio.h>
#include <unistd.h> //sleep

#include "wheels.h"

int main(int argc, char *argv[]) {
    initWheels();
    moveForward();
    printf("Sleep for 5 seconds...\n");
    sleep(5);
    stopWheels();
}
