
#include <amqp.h>
#include <amqp_tcp_socket.h>
#include <utils.h>

#include <channel.hpp>
#include <connection.hpp>
#include <queue.hpp>

#include <exception>
#include <string>
#include <iostream>

channel::channel(connection & conn) : _conn{conn}, _channel_id{conn._channels}
{
    amqp_channel_open(_conn._native_conn, ++_channel_id);
    auto const reply = amqp_get_rpc_reply(_conn._native_conn);//, "Opening channel");
    if(reply.reply_type != AMQP_RESPONSE_NORMAL)
        throw std::runtime_error{"Can't open channel"};
    ++_conn._channels;
}

channel::~channel()
{
    //die_on_amqp_error(amqp_channel_close(conn, 1, AMQP_REPLY_SUCCESS),
    //auto const reply = amqp_channel_close(_conn._conn, 100, AMQP_REPLY_SUCCESS);
    die_on_amqp_error(amqp_channel_close(_conn._native_conn, _channel_id, AMQP_REPLY_SUCCESS),
                      "Closing channel");
    //auto const reply = amqp_channel_close(_conn._native_conn, _channel_id, AMQP_REPLY_SUCCESS);
    //if(reply.reply_type != AMQP_RESPONSE_NORMAL)
    //    std::cout << "Unable to close channel\n";
    //throw std::runtime_error{"Can't close channel"};

    std::cout << "channel closed\n";
}

cpprmq::queue channel::declare_queue(std::string const & queue_name)
{
    const amqp_bytes_t queue_t = {queue_name.size(), (void*)queue_name.c_str()};

    amqp_queue_declare_ok_t *r = amqp_queue_declare(
            _conn._native_conn, _channel_id, queue_t, 0, 0, 0, 1, amqp_empty_table);
    auto const reply = amqp_get_rpc_reply(_conn._native_conn);
    if(reply.reply_type != AMQP_RESPONSE_NORMAL)
        throw std::runtime_error{"Can't declare queue"};
    return cpprmq::queue{queue_name};
}

void channel::basic_publish(std::string const & exchange
                           ,std::string const & routing_key
                           ,std::string const & message)
{
    amqp_basic_properties_t props;
    props._flags = AMQP_BASIC_CONTENT_TYPE_FLAG | AMQP_BASIC_DELIVERY_MODE_FLAG;
    props.content_type  = amqp_cstring_bytes("text/plain");
    props.delivery_mode = 2; /* persistent delivery mode */
    auto const reply    = amqp_basic_publish(_conn._native_conn
                                            ,_channel_id
                                            ,amqp_cstring_bytes(exchange.c_str())
                                            ,amqp_cstring_bytes(routing_key.c_str())
                                            ,0
                                            ,0
                                            ,&props
                                            ,amqp_cstring_bytes(message.c_str()));
    if(reply < 0)
        throw std::runtime_error{"Can't publish message"};
}