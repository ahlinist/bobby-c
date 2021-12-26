#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <amqp.h>
#include <amqp_tcp_socket.h>

#include <assert.h>

#include "rabbitutils.h"
#include "motion.h"

int listen_to_command_queue(int argc, char const *const *argv) {
    char const *hostname;
    int port, status;
    char const *queuename;
    char const *username;
    char const *password;
    amqp_socket_t *socket = NULL;
    amqp_connection_state_t conn;

    hostname = argv[1];
    port = atoi(argv[2]);
    queuename = argv[3];
    username = argv[4];
    password = argv[5];

    conn = amqp_new_connection();

    socket = amqp_tcp_socket_new(conn);
    if (!socket) {
        die("creating TCP socket");
    }

    status = amqp_socket_open(socket, hostname, port);
    if (status) {
        die("opening TCP socket");
    }

    die_on_amqp_error(amqp_login(conn, username, 200, 131072, 0, AMQP_SASL_METHOD_PLAIN, username, password),
                        "Logging in");
    amqp_channel_open(conn, 1);
    die_on_amqp_error(amqp_get_rpc_reply(conn), "Opening channel");
    amqp_basic_consume(conn, 1, amqp_cstring_bytes(queuename), amqp_empty_bytes, 0, 0, 0, amqp_empty_table);
    die_on_amqp_error(amqp_get_rpc_reply(conn), "Consuming");

    {
        for (;;) {
            amqp_envelope_t envelope;
            amqp_maybe_release_buffers(conn);
            amqp_rpc_reply_t res = amqp_consume_message(conn, &envelope, NULL, 0);

            if (AMQP_RESPONSE_NORMAL != res.reply_type) {
                break;
            }

            char direction[0] = "";
            memcpy(direction, envelope.message.body.bytes, sizeof envelope.message.body.bytes);
            move(direction);
            amqp_destroy_envelope(&envelope);
        }
    }

    die_on_amqp_error(amqp_channel_close(conn, 1, AMQP_REPLY_SUCCESS), "Closing channel");
    die_on_amqp_error(amqp_connection_close(conn, AMQP_REPLY_SUCCESS), "Closing connection");
    die_on_error(amqp_destroy_connection(conn), "Ending connection");

    return 0;
}
