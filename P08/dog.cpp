#include "dog.h"
#include <map>
#include <iostream>

std::map<int,std::string> MapofDogs;
// Constructor / Destructor - note how delegation to base class works!
Dog::Dog(Dog_breed breed, std::string name, Gender gender, int age)
    : Animal(name, gender, age), _breed{breed} { }
Dog::~Dog() { }

// Overrides for pure virtual methods
std::string Dog::family() const {return "dog";}
std::string Dog::breed() const {return ::to_string(_breed);}

// Convert breed to string and stream - use a std::map for other derived classes!
std::string to_string(const Dog_breed& breed)
{
    switch(breed) {
        case  Dog_breed::MIX:        return "Mix";
        case  Dog_breed::LABRADOR:   return "Labrador";
        case  Dog_breed::RETRIEVER:  return "Retriever";
        case  Dog_breed::SHEPHERD:   return "Shepherd";
        case  Dog_breed::BULLDOG:    return "Bulldog";
        case  Dog_breed::BEAGLE:     return "Beagle";
        case  Dog_breed::POODLE:     return "Poodle";
        case  Dog_breed::ROTTWEILER: return "Rottweiler";
        case  Dog_breed::POINTER:    return "Pointer";
        case  Dog_breed::TERRIER:    return "Terrier";
        case  Dog_breed::BOXER:      return "Boxer";
        case  Dog_breed::DACHSHUND:  return "Dachshund";
        default:                     return "UNKNOWN";
    }
    int dogselect;
    std::cout << "what kind of dog do you want?" <<std::endl;
    std::cin >> dogselect;
    if (dogselect == 1)
    {
      MapofDogs.insert(make_pair(Dog_breed::BOXER,"Boxer"));
    }
    for (auto it : MapofDogs)
    {
        std::cout << it.first << it.second << std::endl;
    }
}
std::ostream& operator<<(std::ostream& ost, const Dog_breed& breed) {
    ost << ::to_string(breed);
    return ost;
}
