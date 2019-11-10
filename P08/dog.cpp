#include "dog.h"
#include <map>
#include <iostream>

std::map<Dog_breed,std::string> MapofDogs;
// Constructor / Destructor - note how delegation to base class works!
Dog::Dog(Dog_breed breed, std::string name, Gender gender, int age)
    : Animal(name, gender, age), _breed{breed} { }
Dog::~Dog() { }

// Overrides for pure virtual methods
std::string Dog::family() const {return "dog";}
std::string Dog::breed() const {return ::to_string(_breed);}

// Convert breed to string and stream - use a std::map for other derived classes!
    int dogselect;
    std::cout << "what kind of dog do you want?" <<std::endl;
    std::cin >> dogselect;

    if(dogselect == 1)
    {
      MapofDogs.insert(std::make_pair(Dog_breed::BOXER,"Boxer"));
    }
    for(auto it : MapofDogs)
    {
        std::cout << it.first << it.second << std::endl;
    }
}
std::ostream& operator<<(std::ostream& ost, const Dog_breed& breed) {
    ost << ::to_string(breed);
    return ost;
}
