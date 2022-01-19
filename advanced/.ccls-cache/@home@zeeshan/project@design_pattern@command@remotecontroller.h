
#pragma once


#include <vector>
#include "command.h"

class remote
{
	std::vector<command*>_onCommand;
	std::vector<command*>_offCommand;

	remote(const remote &) = delete;
	remote operator = (const remote &) = delete;

	public:
	remote();
	void setCommand(int slot, command * on, command * off);
	void onButtonPressed (int slot) const;
	void offButtonPressed (int slot) const ;
};
