#include <mach/mach.h>

struct message {
    mach_msg_header_t header;
    int data;
};

mach_port_t client;
mach_port_t server;

void client_pass_msg();
void server_rcv_msg();

int main() {
    client_pass_msg();
    server_rcv_msg();
}

        /* Client Code */
void client_pass_msg() {
    struct message message;

    // construct the header
    message.header.msgh_size = sizeof(message);
    message.header.msgh_remote_port = server;
    message.header.msgh_local_port = client;

    // send the message
    mach_msg(&message.header, // message header
             MACH_SEND_MSG, // sending a message
             sizeof(message), // size of message sent
             0, // maximum_size of received message - unnecessary
             MACH_PORT_NULL, // name of receive port - unnecessary
             MACH_MSG_TIMEOUT_NONE, // no time outs
             MACH_PORT_NULL // no notify port
    );
}

        /* Server Code */
void server_rcv_msg() {
    struct message message;

    // receive the message
    mach_msg(&message.header, // message header
             MACH_RCV_MSG, // sending a message
             0, // size of message sent
             sizeof(message), // maximum size of received message
             server, // name of receive port
             MACH_MSG_TIMEOUT_NONE, // no time outs
             MACH_PORT_NULL // no notify port
    );
}