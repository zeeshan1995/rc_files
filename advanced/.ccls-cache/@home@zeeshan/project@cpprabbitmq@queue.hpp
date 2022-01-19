#pragma once

#include <string>


namespace cpprmq
{
    class queue
    {
        public:
            queue(std::string queue_name) : _queue_name{queue_name}{}
            std::string queue_name() const noexcept { return _queue_name; }
        std::string _queue_name;
    };
}