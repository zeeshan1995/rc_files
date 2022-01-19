
#pragma once

#include <algorithm>
#include <iostream>

template<typename T>
class unique_ptr
{
    public:
        unique_ptr() : _ptr{nullptr} {}
        explicit unique_ptr(T* ptr) : _ptr{ptr} {}

        ~unique_ptr()
        {
            std::cout << "in dtr\n";
            if(_ptr)
                delete _ptr;
        }

        unique_ptr<T>& operator=(unique_ptr<T> const &) = delete;
        unique_ptr(unique_ptr<T> const &) = delete;

        unique_ptr<T>& operator=(unique_ptr<T> && other)
        {
            std::cout << "Inside move assingment \n";
            reset(other.release());
            return *this;
        }

        unique_ptr(unique_ptr<T> && other) : _ptr{other.release()}
        {
            std::cout << "inside move ctr\n";
        }

        T* get() const { return _ptr;}
        T* operator->() const {return _ptr;}
        T& operator*() const {return *_ptr;}

        explicit operator bool() const {return _ptr;}

        void reset(T * ptr = nullptr)
        {
            std::swap(_ptr, ptr);
            if(ptr)
                delete ptr;
        }

        T* release()
        {
            T* ptr = nullptr;
            std::swap(ptr, _ptr);
            return ptr;
        }

        void swap(unique_ptr<T> & other)
        {
            std::swap(_ptr, other._ptr);
        }

    private:
        T* _ptr;
};

template<typename T>
void swap(unique_ptr<T> & right, unique_ptr<T> & left)
{
    right.swap(left);
}
