
#include <amqp.h>

#include <connection.hpp>
#include <queue.hpp>

#include <exception>
#include <string>
#include <iostream>



class channel
{
	public: // functions
		channel(connection & conn);

        ~channel();

		cpprmq::queue declare_queue(std::string const & queue_name);

		void basic_publish(std::string const & exchange
						  ,std::string const & routing_key
						  ,std::string const & message);

        //template<typename Worker>
        //void sync_consume(Worker worker
        void sync_consume(int worker
                         ,std::string const & exchange
                         ,std::string const & routing_key);

		template<typename Callable>
        int receive(cpprmq::queue const & queue, Callable const & worker);

	private: // data member
		amqp_channel_t   _channel_id;
		connection	   & _conn;
};
#include <amqp.h>
#include <amqp_tcp_socket.h>
#include <utils.hpp>
template<typename Callable>
int channel::receive(cpprmq::queue const & queue, Callable const & worker)
{
    auto && conn   = this->_conn._native_conn;
    auto && socket = this->_conn._socket;

    amqp_basic_consume(conn, this->_channel_id, amqp_cstring_bytes(queue.queue_name().c_str()),amqp_empty_bytes,
                       0, 0, 0, amqp_empty_table);
    die_on_amqp_error(amqp_get_rpc_reply(conn), "Consuming");

    for (;;)
    {
        amqp_rpc_reply_t res;
        amqp_envelope_t envelope;

        amqp_maybe_release_buffers(conn);

        res = amqp_consume_message(conn, &envelope, NULL, 0);

        if (AMQP_RESPONSE_NORMAL != res.reply_type)
        {
            break;
        }

		worker((const char *)envelope.message.body.bytes);
        amqp_destroy_envelope(&envelope);
    }
    return 0;
}