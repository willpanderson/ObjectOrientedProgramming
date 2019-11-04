#include "dog.h"


Dog::Dog(Breed breed, std::string name, Gender gender, int age) : _breed{breed}, Animal{name,gender,age} 
{
}

Dog::~Dog()
{
}

std::string Dog::family()
{
 return "Dog";
}

std::string Dog::breed()  
{
 
}
