#include <stdio.h>
#include <unistd.h> //sleep

#include "wheels.h"

int main(int argc, char *argv[]) {
    printf("Hello world!\n");
    initWheels();
    moveForward();
    sleep(5);
    stopWheels();
}
