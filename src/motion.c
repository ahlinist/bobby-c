#include "wheels.h"

void init_motion_module() {
    init_wheels();
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
