
class foo
{
    foo(int n) :_n(n) {};
    void set(int n){_n = n;}

    private:
    int _n;
};

int main()
{
    foo s[10];
    const foo* ptr = &s[0];
    for(int i=0; i< 9; ++i)
    {
        ptr->set(i);
        ++ptr;
    }
}
