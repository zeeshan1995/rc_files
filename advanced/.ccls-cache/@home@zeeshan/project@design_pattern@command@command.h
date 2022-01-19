#pragma once


#include <iostream>
#include "./objects.h"

class command
{
	public:
		virtual void execute() const =0;
};


class lightOnCommand : public command
{
	light _light;

	public:
	lightOnCommand(light const & li);
	void execute() const;
};

class lightOffCommand : public command
{
	light _light;
	public:
	lightOffCommand(light const & li);
	void execute() const;
};


class fanOnCommand : public command
{
	fan _fan;
	public:
	fanOnCommand(fan const & f);
	void execute() const;
};

class fanOffCommand : public command
{
	fan _fan;
	public:
	fanOffCommand(fan const & f);
	void execute() const;
};
