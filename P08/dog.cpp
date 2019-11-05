#include "dog.h"


Dog::Dog(Breed breed, std::string name, Gender gender, int age) : Animal{name,gender,age}, _breed{breed} 
{
}

Dog::~Dog()
{
}

std::string Dog::family()
{
  return "dog";
}

std::string Dog::breed()  
{

 switch (_breed) {
 	case Breed::Bloodhound:
             return "Bloodhound";
	case Breed::Rotwiler:
             return "Rotwiler";
	case Breed::Beagle:
             return "Beagle";
	case Breed::Pitbull:
             return "Pitbull";
	case Breed::Bulldog:
             return "Bulldog";
	case Breed::Chihuahua:
             return "Chihuahua";
	case Breed::Samoyed:
             return "Samoyed";
	case Breed::Poodle:
             return "Poodle";
	default:
		return "";
}

return "";

}
