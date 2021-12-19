#include <stdio.h>

#define RIGHT_FORWARD_PIN 22  //BCM pin number, corresponds 15 physical pin number
#define RIGHT_BACKWARD_PIN 23 //BCM pin number, corresponds 16 physical pin number
#define LEFT_FORWARD_PIN 26   //BCM pin number, corresponds 37 physical pin number
#define LEFT_BACKWARD_PIN 12  //BCM pin number, corresponds 32 physical pin number

void stop() {
    printf("Stopping!");
}
