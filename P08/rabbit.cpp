#include "rabbit.h"
#include <map>
// Constructor / Destructor - note how delegation to base class works!
Rabbit::Rabbit(rabbit_breed breed, std::string name, Gender gender, int age)
    : Animal(name, gender, age), _breed{breed} { }
Rabbit::~Rabbit() { }

// Overrides for pure virtual methods
std::string Rabbit::family() const {return "rabbit";}
std::string Rabbit::breed() const {return ::to_string(_breed);}

// Convert breed to string and stream - use a std::map for other derived classes!
std::string to_string(const rabbit_breed& breed)
  {
  std::map<rabbit_breed, std::string> breeds = {
      {rabbit_breed::HARE, "Hare"},
      {rabbit_breed::GIANT, "Giant"},
      {rabbit_breed::FUZZY, "Fuzzy"},
      {rabbit_breed::GOTLAND, "Gotland"},
      {rabbit_breed::HARLEQUIN, "Harlequin"},
      {rabbit_breed::PALOMINO, "Palmonio"},
      {rabbit_breed::SABLE, "Sable"},
      {rabbit_breed::ANGORA, "Angora"},
      {rabbit_breed::DWARF, "Dwarf"},
      {rabbit_breed::WOOLY, "Wooly"},
      {rabbit_breed::CHINCHILLA, "Chinchilla"},
      {rabbit_breed::LIONHEAD, "Lionhead"},
  };

	return breeds[breed];

}

std::ostream& operator<<(std::ostream& ost, const rabbit_breed& breed) 
{
    ost << ::to_string(breed);
    return ost;
}

void Rabbit::save(std::ostream& ost) {ost << _x << ' ' << _y << ' ';}

