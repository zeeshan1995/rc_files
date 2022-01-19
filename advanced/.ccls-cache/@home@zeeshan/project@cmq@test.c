#include <amqp.h>
#include <amqp_framing.h>
int main(int argc, char const * const *argv) {
   amqp_connection_state_t conn;
   conn = amqp_new_connection();
   amqp_destroy_connection(conn);
   return 0;
}
