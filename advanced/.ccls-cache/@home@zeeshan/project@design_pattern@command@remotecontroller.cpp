
#include "remotecontroller.h"
#include "command.h"

remote::remote()
{
	_onCommand = std::vector<command*>(4,NULL);
	_offCommand = std::vector<command*>(4,NULL);
}
void remote::setCommand(int slot, command * on, command * off)
{
	_onCommand[slot] = on;
	_offCommand[slot] = off;
}

void remote::onButtonPressed (int slot) const
{
	std::cout << "here\n";
	_onCommand[slot]->execute();
}

void remote::offButtonPressed (int slot) const
{
	_offCommand[slot]->execute();
}
