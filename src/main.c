#include <stdio.h>
#include <unistd.h> //sleep

#include "motion/motion.h"

int main(int argc, char *argv[]) {
    initMotionModule();
    moveForward();
    sleep(2);
    turnRight();
    sleep(1);
    moveForward();
    sleep(1);
    turnLeft();
    sleep(1);
    moveBack();
    sleep(2);
    stopMotion();
}
