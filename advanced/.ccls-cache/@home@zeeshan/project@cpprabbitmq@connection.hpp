
#pragma once

#include <amqp.h>
#include <amqp_tcp_socket.h>

#include <string>

class connection
{

	public: //functions
		connection();

		connection(std::string host, int port);
        ~connection();
		connection(connection const & conn) = delete;
		connection & operator = (connection const & conn) = delete;

    public:
        friend class channel;

	private: //functions
		void init();

	private: // data memebers
		std::string _host;
		int			_port;
		
		amqp_socket_t			* _socket;
		amqp_connection_state_t   _native_conn;
		amqp_channel_t			  _channels = 0;
};
