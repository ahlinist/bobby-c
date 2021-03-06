#include <stdio.h>
#include <string.h>
#include <unistd.h> //sleep

#include "filewriter.h"

#define RIGHT_FORWARD_PIN 22  //BCM pin number, corresponds 15 physical pin number
#define RIGHT_BACKWARD_PIN 23 //BCM pin number, corresponds 16 physical pin number
#define LEFT_FORWARD_PIN 26   //BCM pin number, corresponds 37 physical pin number
#define LEFT_BACKWARD_PIN 12  //BCM pin number, corresponds 32 physical pin number

#define PINS_COUNT 4
#define PINS (int[PINS_COUNT]){ RIGHT_FORWARD_PIN, RIGHT_BACKWARD_PIN, LEFT_FORWARD_PIN, LEFT_BACKWARD_PIN }

#define OUT_DIRECTION "out"

#define LOW  "0" //0.0V at pin output
#define HIGH "1" //3.3V at pin output

#define GPIO_EXPORT_FILE_PATH "/sys/class/gpio/export"
#define GPIO_PATH_PREFIX "/sys/class/gpio/gpio"
#define VALUE_PATH_SUFFIX "/value"
#define DIRECTION_SUFFIX "/direction"

void export_pins(); 
void set_pin_directions();
void write_pin_value(int pin, char *value);

void init_wheels() {
    export_pins();
    sleep(1);
    set_pin_directions(OUT_DIRECTION);
}

void export_pins() {
    printf("Exporting pins...\n");

    for (int i = 0; i < PINS_COUNT; i++) {
        char pinNumber[2];
        sprintf(pinNumber, "%d", PINS[i]);
        write_to_file(GPIO_EXPORT_FILE_PATH, pinNumber);
    }

    printf("Pins export complete...\n");
}

void set_pin_directions() {
    printf("Setting directions...\n");

    for (int i = 0; i < PINS_COUNT; i++) {
        char directionFile[255];
        sprintf(directionFile, "%s%d%s", GPIO_PATH_PREFIX, PINS[i], DIRECTION_SUFFIX);
        write_to_file(directionFile, OUT_DIRECTION);
    }

    printf("Directions definition complete...\n");
}

void right_wheel_forward() {
    write_pin_value(RIGHT_FORWARD_PIN, HIGH);
}

void left_wheel_forward() {
    write_pin_value(LEFT_FORWARD_PIN, HIGH);
}

void right_wheel_back() {
    write_pin_value(RIGHT_BACKWARD_PIN, HIGH);
}

void left_wheel_back() {
    write_pin_value(LEFT_BACKWARD_PIN, HIGH);
}

void stop_wheels() {
    for (int i = 0; i < PINS_COUNT; i++) {
        write_pin_value(PINS[i], LOW);
    }
}

void write_pin_value(int pin, char *value) {
    char pathToFile[255];
    sprintf(pathToFile, "%s%d%s", GPIO_PATH_PREFIX, pin, VALUE_PATH_SUFFIX);
    write_to_file(pathToFile, value);
}
