#include <amqp.h>
#include <amqp_framing.h>

#include <iostream>


void test(amqp_connection_state_t con)
{
	std::cout << "hello\n";
}

int main(int argc, char const * const *argv) {
   amqp_connection_state_t conn;
   conn = amqp_new_connection();
   amqp_destroy_connection(conn);

   std::cout << "Hello world\n";
   return 0;
}
