#include <stdio.h>

#include "filewriter.h"

#define RIGHT_FORWARD_PIN 22  //BCM pin number, corresponds 15 physical pin number
#define RIGHT_BACKWARD_PIN 23 //BCM pin number, corresponds 16 physical pin number
#define LEFT_FORWARD_PIN 26   //BCM pin number, corresponds 37 physical pin number
#define LEFT_BACKWARD_PIN 12  //BCM pin number, corresponds 32 physical pin number

#define OUT_DIRECTION "out"

#define LOW  0 //0.0V at pin output
#define HIGH 1 //3.3V at pin output

#define BUFFER_MAX 3 //max size of buffer written to sysf

void initWheels() {
    writeToFile("/sys/class/gpio/export", RIGHT_FORWARD_PIN);
    writeToFile("/sys/class/gpio/export", RIGHT_BACKWARD_PIN);
    writeToFile("/sys/class/gpio/export", LEFT_FORWARD_PIN);
    writeToFile("/sys/class/gpio/export", LEFT_BACKWARD_PIN);
}

void stop() {
    printf("Stopping!");
}
