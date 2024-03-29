#pragma once

void die(const char *fmt, ...);
void die_on_error(int x, char const *context);
void die_on_amqp_error(amqp_rpc_reply_t x, char const *context);

void amqp_dump(void const *buffer, size_t len);

extern uint64_t now_microseconds(void);
extern void microsleep(int usec);

