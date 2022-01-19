

#pragma once


#include <string>
#include <memory>
#include <iostream>

class foo
{
    public:
        foo(int a){std::cout << "ctr\n";}
        ~foo(){std::cout << "dtr\n";}
        foo(foo const &){std::cout << "copy ctr\n";}
        foo& operator=(foo const &){std::cout << "copy assignment\n"; return *this;}
        foo(foo &&){std::cout << "move ctr\n";}
        foo& operator=(foo &&){std::cout << "move assignment\n"; return *this;}
};


class strvec
{
    public:
        strvec() : _begin{nullptr}, _end{nullptr}, _physical_end{nullptr} {}
        strvec(strvec const & other);
        strvec& operator=(strvec const & other);
        ~strvec();

        void push_back(foo const & str);
        std::size_t size() const {return _end - _begin;}
        std::size_t capacity() const {return _physical_end - _begin;}
        foo *begin() const {return _begin;}
        foo *end() const {return _end;}

    private:
        std::allocator<foo> alloc;
        void check_n_alloc() { if(size() == capacity()) reallocate();}
        std::pair<foo*, foo*> alloc_n_copy(foo const *, foo const *);
        void free();
        void reallocate();

    private:
        foo * _begin;
        foo * _end;
        foo * _physical_end;
};

void strvec::push_back(foo const & s)
{
    check_n_alloc();
    alloc.construct(_end++, s);
}

std::pair<foo*, foo*> strvec::alloc_n_copy(foo const* b, foo const * e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void strvec::free() 
{
    if(_begin)
    {
        for(auto p = _end; p != _begin;)
            alloc.destroy(--p);
        alloc.deallocate(_begin, _physical_end - _begin);
    }
}

strvec::~strvec()
{
    free();
}

strvec::strvec(strvec const & vec)
{
    auto data = alloc_n_copy(vec.begin(), vec.end());
    _begin = data.first;
    _end = _physical_end = data.second;
}

strvec& strvec::operator=(strvec const & other)
{
    auto data = alloc_n_copy(other.begin(), other.end());
    free();
    _begin = data.first;
    _end = _physical_end = data.second;
    return *this;
}

void strvec::reallocate()
{
    auto capacity = size() ? 2 * size() : 1;
    auto data = alloc.allocate(capacity);
    auto dest = data;
    for(auto & elem: *this)
        alloc.construct(dest++, std::move(elem));
    free();
    _begin = data;
    _end = dest;
    _physical_end = data + capacity;
}
