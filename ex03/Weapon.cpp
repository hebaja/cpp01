#include "Weapon.hpp"
#include <string>

Weapon::Weapon(std::string type)
{
	setType(type);
}

Weapon::Weapon(){}

Weapon::~Weapon(){}

std::string  Weapon::getType()
{
	return (this->type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
