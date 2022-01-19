
#include <amqp.h>
#include <amqp_tcp_socket.h>
#include <utils.h>

#include <connection.hpp>

#include <exception>
#include <string>
#include <iostream>

connection::connection() : _host{"localhost"}, _port{5672} {init();}

connection::connection(std::string host
					  ,int         port)
				: _host{std::move(host)}
				 ,_port{std::move(port)}
				 {init();}

connection::~connection()
{
  //die_on_amqp_error(amqp_connection_close(conn, AMQP_REPLY_SUCCESS),
  //auto const reply = amqp_connection_close(_native_conn, AMQP_REPLY_SUCCESS);
  //die_on_error(amqp_destroy_connection(_native_conn), "Ending connection");
  //if(reply.reply_type != AMQP_RESPONSE_NORMAL)
  //    std::cout << "Unable to close connection\n";
  //    //throw std::runtime_error{"Can't close channel"};

  //std::cout << "connection closed\n";
    die_on_amqp_error(amqp_connection_close(_native_conn, AMQP_REPLY_SUCCESS),
                      "Closing connection");
    die_on_error(amqp_destroy_connection(_native_conn), "Ending connection");
  std::cout << "connection closed\n";
}

auto connection::init()
	-> void
{
	_native_conn   = amqp_new_connection();
	_socket = amqp_tcp_socket_new(_native_conn);
	if(not _socket)
		throw std::runtime_error{"Can't create socket"};

	auto const status = amqp_socket_open(_socket, _host.c_str(), _port);
	if(status)
		throw std::runtime_error{"Can't open socket"};

	auto const reply = amqp_login(_native_conn, "/", 0, 131072, 0, AMQP_SASL_METHOD_PLAIN, "guest", "guest");
	if(reply.reply_type != AMQP_RESPONSE_NORMAL)
		throw std::runtime_error{"Can't login"};
}

