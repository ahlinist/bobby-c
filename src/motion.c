#include "wheels.h"

void initMotionModule() {
    initWheels();
}

void moveForward() {
    stopWheels();
    rightWheelForward();
    leftWheelForward();
}

void moveBack() {
    stopWheels();
    rightWheelBack();
    leftWheelBack();
}

void turnRight() {
    stopWheels();
    rightWheelForward();
    leftWheelBack();
}

void turnLeft() {
    stopWheels();
    leftWheelForward();
    rightWheelBack();
}

void stopMotion() {
    stopWheels();
}
