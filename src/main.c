#include "amqplistener.h"
#include "motion.h"

int main(int argc, char *argv[]) {
    init_motion_module();
    return listen_to_command_queue();
}
