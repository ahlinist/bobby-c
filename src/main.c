#include <stdio.h>
#include <unistd.h> //sleep

#include "motion.h"

int main(int argc, char *argv[]) {
    initMotionModule();
    moveForward();
    sleep(3);
    turnRight();
    sleep(1);
    moveForward();
    sleep(3);
    turnLeft();
    sleep(1);
    moveBack(6);
    stopMotion();
}
