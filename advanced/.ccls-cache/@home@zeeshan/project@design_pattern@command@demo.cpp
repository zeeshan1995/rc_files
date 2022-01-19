

#include <iostream>
#include "objects.h"
#include "remotecontroller.h"
#include "command.h"


int main()
{
	remote newRemote;

	light roomLight("room light");
	light kitchenLight("kitchen light");

	fan roomFan("Room fan");
	fan kitchenFan("Kitchen Fan");

	newRemote.setCommand(0,new lightOnCommand(roomLight), new lightOffCommand(roomLight));
	newRemote.setCommand(1,new lightOnCommand(kitchenLight), new lightOffCommand(kitchenLight));
	newRemote.setCommand(2,new fanOnCommand(roomFan), new fanOffCommand(roomFan));
	newRemote.setCommand(3,new fanOnCommand(kitchenFan), new fanOffCommand(kitchenFan));

	for(int i=0; i<4; i++)
		newRemote.onButtonPressed(i);
}
