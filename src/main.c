#include <stdio.h>
#include <unistd.h> //sleep

#include "motion.h"

int main(int argc, char *argv[]) {
    initMotionModule();
    moveForward();
    sleep(6);
    turnRight();
    sleep(0.5);
    moveForward();
    sleep(3);
    turnLeft();
    sleep(0.5);
    moveBack();
    sleep(6);
    stopMotion();
}
