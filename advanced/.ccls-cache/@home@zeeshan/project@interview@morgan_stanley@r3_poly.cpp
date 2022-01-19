



class A
{
    public:
        virtual void print() { std::cout << "A" << std::endl;}
};

class B : public A
{
    public:
        void print() { std::cout << "B" << std::endl;}
};


int main()
{
    A * a = new B{};
    a->print(); // B
}
