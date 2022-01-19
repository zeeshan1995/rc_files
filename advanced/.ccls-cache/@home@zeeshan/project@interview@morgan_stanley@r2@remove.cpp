



1 2 5 6 14 15 18 20 23

1 2 6 14 18 23 5 15 20
namespace foo
{
    template <typename Container, typename Callable>
    Container::iterator remove_if(Container::iterator begin, Container::interator end, T callable)
    {

        auto cur = begin;
        while(cur!=end && !callable(cur))
            ++curr;

        if(cur == end)
            return cur;
       //cur --> 5 
        for(begin=cur+1; begin!=end; ++begin)
        {
            if(!callable(*begin))
            {
                *cur = *begin;
                ++cur;
            }
        }
        return cur;
    }

    //T --> pointer, continer, object
    int sizeof(unsigned n)
    {

    }
}



