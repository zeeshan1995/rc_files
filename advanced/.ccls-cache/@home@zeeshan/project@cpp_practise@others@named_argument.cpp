

#include <iostream>
#include <map>

class named_argument
{
	private:

		struct inner
		{
			public:
				template<typename T>
				static std::map<int, T>args;
		};

	public:
		template<typename T>
		void insert(int key, T && val)
		{
			inner::args<T>[key] = val;
		}

		void get(int key)
		{
			return inner::args
		}

};

template<typename T>
std::map<int, T> named_argument::inner::args;

//template<typename T>
//std::map<int, T> args;

int main()
{
	named_argument args;
	args.insert(1, 23);
	args.insert(2, std::string{"zeeshan"});
	//args.insert(2, "char *");
	//args.insert(3, std::string{"string"});
}
