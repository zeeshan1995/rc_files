

#include <iostream>
#include <vector>

class shape
{
	public:
		shape()
		{
			draw();
		}
		virtual ~shape(){std::cout << "Shape Descructor\n";}
		virtual void draw()=0;
};

void shape::draw()
{
	std::cout << "Shape\n";
}
class circle : public shape
{
	public:
		circle(){std::cout << "Constructor Circle\n";}
		~circle(){std::cout << "Disstructor Circle\n";}
		void draw()
		{
			std::cout << "Circle\n";
		}
};

class square : public shape
{
	public:
		void draw()
		{
			std::cout << "square\n";
		}
};
class triangle : public shape
{
	public:
		void draw()
		{
			std::cout << "Triangle\n";
		}
};
int main()
{
	std::vector<shape*>shapes = { new circle,
		new square,
		new triangle};
	for(auto x : shapes)
	{
		x->draw();
		delete x;
	}
}
