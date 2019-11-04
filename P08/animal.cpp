#include "animal.h"

Animal::Animal(std::string name, Gender gender,int age): _name{name},_gender{gender},_age{age}
{

}

Animal::~Animal()
{
}

Animal::family()
{
}

Animal::breed()
{
}

Animal::name()
{
 return _name;
}

Animal::gender()
{
 return _gender;
}

Animal::age() 
{
 return _age;
}

std::string Animal::to_string()
{
 return _name + "\n" + std::to_string(_gender) + "\n" + std::string(_age) + "\n"
}
