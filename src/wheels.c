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

char PINS[4][3] = { RIGHT_FORWARD_PIN, RIGHT_BACKWARD_PIN, LEFT_FORWARD_PIN, LEFT_BACKWARD_PIN };

void initWheels() {
    printf("Start wheels init...\n");

    for (int i = 0; i < sizeof(PINS); i++) {

        printf("picking a pin...\n");

        char *pinNumber = PINS[i];

        printf("init pin %s \n", pinNumber);

        writeToFile("/sys/class/gpio/export", pinNumber);

        printf("initialization done: %s \n", pinNumber);


        char *directionFile = strcat(strcat("/sys/class/gpio/gpio", pinNumber), "/direction");
        writeToFile(directionFile, OUT_DIRECTION);
    }

    printf("Wheels initialized.\n");
}

void moveForward() {
    char *rightForwardValueFile = strcat(strcat("/sys/class/gpio/gpio", RIGHT_FORWARD_PIN), "/value");
    char *leftForwardValueFile = strcat(strcat("/sys/class/gpio/gpio", LEFT_FORWARD_PIN), "/value");
    writeToFile(rightForwardValueFile, HIGH);
    writeToFile(leftForwardValueFile, HIGH);

}

void stopWheels() {
    for (int i = 0; i < sizeof(PINS); i++) {
        char *rightForwardValueFile = strcat(strcat("/sys/class/gpio/gpio", RIGHT_FORWARD_PIN), "/value");
        writeToFile(rightForwardValueFile, LOW);
    }
}
