
#pragma once

#include <string>

class light
{
	std::string _name;
	public:

	light(std::string);
	void on() const ;
	void off() const; 
};

class fan
{
	std::string _name;

	public:

	fan(std::string);
	void on() const; 
	void off() const; 
};
