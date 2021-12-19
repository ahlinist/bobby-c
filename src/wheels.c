#include <stdio.h>
#include <string.h>

#include "filewriter.h"

#define RIGHT_FORWARD_PIN "22"  //BCM pin number, corresponds 15 physical pin number
#define RIGHT_BACKWARD_PIN "23" //BCM pin number, corresponds 16 physical pin number
#define LEFT_FORWARD_PIN "26"   //BCM pin number, corresponds 37 physical pin number
#define LEFT_BACKWARD_PIN "12"  //BCM pin number, corresponds 32 physical pin number

#define OUT_DIRECTION "out"

#define LOW  "0" //0.0V at pin output
#define HIGH "1" //3.3V at pin output

#define GPIO_PATH_PREFIX "/sys/class/gpio/gpio"
#define VALUE_PATH_POSTFIX "/value"

char PINS[4][3] = { RIGHT_FORWARD_PIN, RIGHT_BACKWARD_PIN, LEFT_FORWARD_PIN, LEFT_BACKWARD_PIN };

void initWheels() {
    printf("Start wheels init...\n");

    for (int i = 0; i < sizeof(PINS); i++) {

        printf("picking a pin...\n");

        char *pinNumber = PINS[i];

        printf("init pin %s \n", pinNumber);

        writeToFile("/sys/class/gpio/export", pinNumber);

        printf("initialization done: %s \n", pinNumber);

        char *directionFile = GPIO_PATH_PREFIX;
        strcat(directionFile, pinNumber);
        strcat(directionFile, "/direction");

        printf("%s \n", directionFile);

        writeToFile(directionFile, OUT_DIRECTION);

        printf("direction for pin %s is set \n", pinNumber);
    }

    printf("Wheels initialized.\n");
}

void moveForward() {
    char *rightForwardValueFile = GPIO_PATH_PREFIX;
    strcat(rightForwardValueFile, LEFT_FORWARD_PIN);
    strcat(rightForwardValueFile, VALUE_PATH_POSTFIX);
    char *leftForwardValueFile = GPIO_PATH_PREFIX;
    strcat(leftForwardValueFile, LEFT_FORWARD_PIN);
    strcat(leftForwardValueFile, VALUE_PATH_POSTFIX);
    writeToFile(rightForwardValueFile, HIGH);
    writeToFile(leftForwardValueFile, HIGH);
}

void stopWheels() {
    for (int i = 0; i < sizeof(PINS); i++) {
        char *pathToValueFile = GPIO_PATH_PREFIX;
        strcat(pathToValueFile, PINS[i]);
        strcat(pathToValueFile, VALUE_PATH_POSTFIX);
        writeToFile(pathToValueFile, LOW);
    }
}
