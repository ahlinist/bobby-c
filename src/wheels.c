#include <stdio.h>
#include <string.h>

#include "filewriter.h"

#define RIGHT_FORWARD_PIN "22"  //BCM pin number, corresponds 15 physical pin number
#define RIGHT_BACKWARD_PIN "23" //BCM pin number, corresponds 16 physical pin number
#define LEFT_FORWARD_PIN "26"   //BCM pin number, corresponds 37 physical pin number
#define LEFT_BACKWARD_PIN "12"  //BCM pin number, corresponds 32 physical pin number

#define PINS_COUNT 4

#define OUT_DIRECTION "out"

#define LOW  "0" //0.0V at pin output
#define HIGH "1" //3.3V at pin output

#define GPIO_PATH_PREFIX "/sys/class/gpio/gpio"
#define VALUE_PATH_POSTFIX "/value"

char PINS[4][3] = { RIGHT_FORWARD_PIN, RIGHT_BACKWARD_PIN, LEFT_FORWARD_PIN, LEFT_BACKWARD_PIN };

void initWheels() {
    for (int i = 0; i < PINS_COUNT; i++) { //-1 to ignore \n character
        char *pinNumber = PINS[i];
        writeToFile("/sys/class/gpio/export", pinNumber);

        char directionFile[255] = GPIO_PATH_PREFIX;
        strcat(directionFile, pinNumber);
        strcat(directionFile, "/direction");
        writeToFile(directionFile, OUT_DIRECTION);
    }
}

void moveForward() {
    char rightForwardValueFile[255] = GPIO_PATH_PREFIX;
    strcat(rightForwardValueFile, RIGHT_FORWARD_PIN);
    strcat(rightForwardValueFile, VALUE_PATH_POSTFIX);
    char leftForwardValueFile[255] = GPIO_PATH_PREFIX;
    strcat(leftForwardValueFile, LEFT_FORWARD_PIN);
    strcat(leftForwardValueFile, VALUE_PATH_POSTFIX);
    writeToFile(rightForwardValueFile, HIGH);
    writeToFile(leftForwardValueFile, HIGH);
}

void stopWheels() {
    for (int i = 0; i < PINS_COUNT; i++) {
        char pathToValueFile[255] = GPIO_PATH_PREFIX;
        strcat(pathToValueFile, PINS[i]);
        strcat(pathToValueFile, VALUE_PATH_POSTFIX);
        writeToFile(pathToValueFile, LOW);
    }
}
