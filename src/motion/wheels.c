#include <stdio.h>
#include <string.h>
#include <unistd.h> //sleep

#include "../util/filewriter.h"

#define RIGHT_FORWARD_PIN 22  //BCM pin number, corresponds 15 physical pin number
#define RIGHT_BACKWARD_PIN 23 //BCM pin number, corresponds 16 physical pin number
#define LEFT_FORWARD_PIN 26   //BCM pin number, corresponds 37 physical pin number
#define LEFT_BACKWARD_PIN 12  //BCM pin number, corresponds 32 physical pin number

#define PINS_COUNT 4
#define PINS (int[PINS_COUNT]){ RIGHT_FORWARD_PIN, RIGHT_BACKWARD_PIN, LEFT_FORWARD_PIN, LEFT_BACKWARD_PIN }

#define OUT_DIRECTION "out"

#define LOW  "0" //0.0V at pin output
#define HIGH "1" //3.3V at pin output

#define GPIO_PATH_PREFIX "/sys/class/gpio/gpio"
#define VALUE_PATH_POSTFIX "/value"

void exportPins(); 
void setPinDirections();
void writeValue(int pin, char *value);

void initWheels() {
    exportPins();
    sleep(1);
    setPinDirections(OUT_DIRECTION);
}

void exportPins() {
    printf("Exporting pins...\n");

    for (int i = 0; i < PINS_COUNT; i++) {
        char pinNumber[2];
        sprintf(pinNumber, "%d", PINS[i]);
        writeToFile("/sys/class/gpio/export", pinNumber);
    }

    printf("Pins export complete...\n");
}

void setPinDirections() {
    printf("Setting directions...\n");

    for (int i = 0; i < PINS_COUNT; i++) {
        char directionFile[255];
        sprintf(directionFile, "%s%d%s", GPIO_PATH_PREFIX, PINS[i], "/direction");
        writeToFile(directionFile, OUT_DIRECTION);
    }

    printf("Directions definition complete...\n");
}

void rightWheelForward() {
    writeValue(RIGHT_FORWARD_PIN, HIGH);
}

void leftWheelForward() {
    writeValue(LEFT_FORWARD_PIN, HIGH);
}

void rightWheelBack() {
    writeValue(RIGHT_BACKWARD_PIN, HIGH);
}

void leftWheelBack() {
    writeValue(LEFT_BACKWARD_PIN, HIGH);
}

void stopWheels() {
    for (int i = 0; i < PINS_COUNT; i++) {
        writeValue(PINS[i], LOW);
    }
}

void writeValue(int pin, char *value) {
    char pathToFile[255];
    sprintf(pathToFile, "%s%d%s", GPIO_PATH_PREFIX, pin, VALUE_PATH_POSTFIX);
    writeToFile(pathToFile, value);
}
