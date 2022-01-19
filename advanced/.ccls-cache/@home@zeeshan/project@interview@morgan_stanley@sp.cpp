

n+=1;
return n;
class shared_ptr
{
    public:
        shared_ptr(int * ptr) : _ptr{ptr}, _ref_count{new int{1}} {}
        shared_ptr(const shared_ptr & other) : _ptr{other._ptr}, _ref_count{other._ref_count}
        {
            //++(*_ref_count);
            std::lock_guard<std::mutex>lock(_mutex);
            *_ref_count = *_ref_count + 1;
            //ref = 2 -> 2
        }

        ~shared_ptr()
        {
            std::lock_guard<std::mutex>lock(_mutex);
            while(!int_dctr)
            int_dctr = true;
            *_ref_count = *_ref_count - 1;
            if(*_ref_count == 0 and _ptr)
            {
                delete _ptr;
                delete _ref_count;
            }
        }

    private:
        int * _ptr;
        int * _ref_count;
        std::mutex * _mutex;
};


int * n = new int(23);

f(n);
shared_ptr(n);
