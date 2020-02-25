#include "dog.h"

// Constructor / Destructor - note how delegation to base class works!
Dog::Dog(Dog_breed breed, std::string name, Gender gender, int age)
    : Animal(name, gender, age), _breed{breed} { }
Dog::~Dog() { }

// File I/O
Dog::Dog(std::istream& ist) : Animal(ist) {
  std::string s;
  getline(ist, s);
  for(auto& [breed, breed_name] : dogs_map)
      if(s == breed_name) {_breed = breed; break;}

}

void Dog::save(std::ostream& ost) {
    ost << "Dog\n";
    Animal::save(ost);
    ost << breed() << '\n';
}

// Overrides for pure virtual methods
std::string Dog::family() const {return "dog";}
std::string Dog::breed() const {return ::to_string(_breed);}

// Convert breed to string and stream - use a std::map for other derived classes!

          
const std::map<Dog_breed, std::string> dogs_map = {
          {Dog_breed::MIX        ,"Mix"},
          {Dog_breed::LABRADOR   , "Labrador"},
          {Dog_breed::RETRIEVER  , "Retriever"}, 
          {Dog_breed::SHEPHERD   , "Shepherd"}, 
          {Dog_breed::BULLDOG    , "Bulldog"}, 
          {Dog_breed::BEAGLE     , "Beagle"},
          {Dog_breed::POODLE     , "Poodle"},
          {Dog_breed::ROTTWEILER , "Rottweiler"}, 
          {Dog_breed::POINTER    , "Pointer"},
          {Dog_breed::TERRIER    , "Terrier"}, 
          {Dog_breed::BOXER      , "Boxer"}, 
          {Dog_breed::DACHSHUND  , "Dachshund"}, 
};
std::string to_string(const Dog_breed& breed) {
    try {
        return dogs_map.at(breed);
    } catch (std::exception& e) {
        return "Unknown";
    }
}
// Streaming I/O
std::ostream& operator<<(std::ostream& ost, const Dog_breed& breed) {
    ost << ::to_string(breed);
    return ost;
}
