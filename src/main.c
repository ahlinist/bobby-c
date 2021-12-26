#include <stdio.h>
#include <unistd.h> //sleep

#include "motion.h"

int main(int argc, char *argv[]) {
    init_motion_module();
    move_forward();
    sleep(2);
    turn_right();
    sleep(1);
    move_forward();
    sleep(1);
    turn_left();
    sleep(1);
    move_back();
    sleep(2);
    stop_motion();
}
