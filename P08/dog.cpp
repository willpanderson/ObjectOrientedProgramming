#include "dog.h"
#

Dog::Dog(dog_breed breed, std::string name, Gender gender, int age) : _breed{breed}, Animal(name,gender,age); 
{
}

void ~Dog()
{
}

Dog::family()
{
 std::string dog = "Dog";
 return std::to_string(dog);
}

Dog::breed() : _breed{breed}
{
 //switch case
}
