#include "shelter.h"


void Shelter(std::string name)
{
}

std::string Shelter::name()
{
 return _name;
}

void Shelter::add_animal (Animal& animal)
{
 return _avalible.push_back(&animal);
}

int Shelter::num_animals()
{
 return _avalible.size();
}

Animal& Shelter::animal(int index)
{
 //return _avalible[index];
}
