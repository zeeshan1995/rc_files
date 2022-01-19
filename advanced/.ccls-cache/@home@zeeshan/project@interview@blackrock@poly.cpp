



int sum(int a, int b)
{
    return a +b;
}
double sum(int a, int b, int b=0);
sum(4,5);

class Foo
{
    public:
    virual void say(int a) = 0
    {
        std::cout << "foo\n";
    }
    Foo(const Foo & other) : _ptr{new int(*(other._ptr))} {}
    Foo & operator=(const Foo other) 
    {
        //delete _ptr;
        _ptr = other._ptr;
        other._ptr = nullptr;// new int(*(other._ptr));
        return *this;
    }

    ~Foo()
    {
        delete _ptr;
    }
    private:
    int * _ptr;
};

class Bar: public Foo
{
    public:
    using Foo::say;
    void say(double b)
    {
        std::cout << "bar\n";
    }
};


Foo * f = new Bar{};
f->say();

Bar b1;
b1.say(5);
Foo f1 = b1;
f1.say();
