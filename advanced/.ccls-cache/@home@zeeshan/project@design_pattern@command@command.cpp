

#include "./objects.h"
#include "./command.h"



lightOnCommand::lightOnCommand(light const & li) : _light(li) {}

void lightOnCommand::execute() const { _light.on(); }

lightOffCommand::lightOffCommand(light const & li) : _light(li) {}

void lightOffCommand::execute() const { _light.off(); }



fanOnCommand::fanOnCommand(fan const & f) : _fan(f) {}

void fanOnCommand::execute() const { _fan.on(); }



fanOffCommand::fanOffCommand(fan const & f) : _fan(f) {}

void fanOffCommand::execute() const { _fan.off(); }
