#include "wheels.h"

#define FORWARD "FORWARD"
#define BACK "BACK"
#define RIGHT "RIGHT"
#define LEFT "LEFT"
#define STOP "STOP"

void move_forward();
void move_back();
void turn_right();
void turn_left();
void stop_motion();

void init_motion_module() {
    init_wheels();
}

void move(char direction[]) {
    if (FORWARD == direction) {
        move_forward();
    } else if (BACK == direction) {
        move_back();
    } else if (RIGHT == direction) {
        turn_right();
    } else if (LEFT == direction) {
        turn_left();
    } else if (STOP == direction) {
        stop_motion();
    }
}

void move_forward() {
    stop_wheels();
    right_wheel_forward();
    left_wheel_forward();
}

void move_back() {
    stop_wheels();
    right_wheel_back();
    left_wheel_back();
}

void turn_right() {
    stop_wheels();
    right_wheel_forward();
    left_wheel_back();
}

void turn_left() {
    stop_wheels();
    left_wheel_forward();
    right_wheel_back();
}

void stop_motion() {
    stop_wheels();
}
