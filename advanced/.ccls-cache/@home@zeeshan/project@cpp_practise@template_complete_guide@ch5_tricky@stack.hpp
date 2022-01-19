
#include <iostream>
#include <vector>
#include <cassert>
namespace zee
{

	template <typename T>
	class stack
	{
		public:
			void push(T const & elem);
			void pop();

			T const & top() const;
			bool empty() const{return elems.empty();}

			template <typename U>
			friend std::ostream & operator<< (std::ostream & out, stack<U> const & s);
		
			template<typename>
			friend class stack;

			template <typename U>
			stack<T>& operator=(stack<U> const &);
		
		private:
			std::vector<T> elems;

			void _print(std::ostream & out) const;
	};


	template <typename T>
	void stack<T>::push(T const & elem){ elems.push_back(elem);}

	template <typename T>
	void stack<T>::pop()
	{
		assert(!elems.empty());
		elems.pop_back();
	}

	template <typename T>
	T const & stack<T>::top() const
	{
		assert(!elems.empty());
		return elems.back();
	}

	template<typename T>
	void stack<T>::_print(std::ostream & out) const
	{
		out << "[";
		for(auto const & elem : elems)
			out << elem << ", ";
		out << "]";
	}

	template <typename T>
	std::ostream & operator<< (std::ostream & out, stack<T> const & s)
	{
		s._print(out);
		return out;
	}

	template <typename T>
	template<typename U>
	stack<T>& stack<T>::operator=(stack<U> const & other)
	{
		stack<U> tmp(other);
		elems.clear();

		for(auto const & x : tmp.elems)
			elems.push_back(x);
		return *this;
	}
}
