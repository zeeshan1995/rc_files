
#include "./objects.h"
#include <string>
#include <iostream>

light::light(std::string name) : _name(name) {}
void light::on() const {std::cout <<_name << " turned on\n"; }
void light::off() const { std::cout << _name << " turned off.\n"; }


fan::fan(std::string name) : _name(name) {}
void fan::on() const {std::cout <<_name << " turned on\n"; }
void fan::off() const { std::cout << _name << " turned off.\n"; }
