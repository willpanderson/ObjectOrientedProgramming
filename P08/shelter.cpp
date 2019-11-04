#include "shelter.cpp"


void Shelter(std::string name) :_name{name} 
{
}

void ~Animal()
{
}

std::string Shelter::name() :_name
{
 return _name;
}

Shelter::add_animal (Animal& animal)
{
 return _avalible.push_back(animal);
}

int Shelter::num_animals()
{
return _avalible.size();
}

Animal& Shelter::animal(int index)
{
 return _avalible[index];
}
