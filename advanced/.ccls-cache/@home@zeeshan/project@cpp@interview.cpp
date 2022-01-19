class A
{
	int number;
	B b;
	C *c;

	A(const A & a)

	{
		this->number = a.number;
		this->b = a.b;
		this->c = a.c? new C(*(a.c)) : nullptr;
	}
}

class Person
{
	std::string name;
	int age;
	double height;

	public:

	Person(){};
	Person(std::string name, int age, double height)
		: name(name), age(age), height(height)
	{
	}

	/* 
	 *        Person(const Person & p)
	 *               : name(p.name), etc(p.etc) 
	 *                      {
	 *                             }
	 *                                   */
};


A * x = new B(3);
x->hello();

int main()
{
	std::vector<Person>persons = {{"A",20,5.6},{"B",30,6.1}, {"C",20,6}};

	std::sort(person.begin(), person.end(), [](Person const & a, person const & b){ return a.age < b.age;})
	
}
