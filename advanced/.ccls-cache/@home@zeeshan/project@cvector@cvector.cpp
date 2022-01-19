
#include "cvector.h"

#include <vector>
#include <iostream>

cvector create_vector(int size)
{
	std::vector<int> * v = new std::vector<int>(size);
	return reinterpret_cast<cvector>(v);
}

void push_back(cvector v, int data)
{
	auto * cppv = reinterpret_cast<std::vector<int>*>(v);
	cppv->push_back(data);
}

int size(cvector v)
{
	auto * cppv = reinterpret_cast<std::vector<int>*>(v);
	return cppv->size();
}

void print(cvector v)
{
	auto * cppv = reinterpret_cast<std::vector<int>*>(v);
	std::cout << "[ ";
	for(auto const & item : *cppv)
		std::cout << item << " ";
	std::cout << "]\n";
}
