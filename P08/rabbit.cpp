#include "rabbit.h"

// Constructor / Destructor - note how delegation to base class works!
Rabbit::Rabbit(rabbit_breed breed, std::string name, Gender gender, int age)
    : Animal(name, gender, age), _breed{breed} { }
Rabbit::~Rabbit() { }

// Overrides for pure virtual methods
std::string Rabbit::family() const {return "Rabbit";}
std::string Rabbit::breed() const {return ::to_string(_breed);}

// Convert breed to string and stream - use a std::map for other derived classes!
std::string to_string(const rabbit_breed& breed) {
    switch(breed) {
        case  rabbit_breed::HARE:       return "Hare";
        case  rabbit_breed::GIANT:      return "Giant";
        case  rabbit_breed::FUZZY:      return "Fuzzy";
        case  rabbit_breed::GOTLAND:    return "Gotland";
        case  rabbit_breed::HARLEQUIN:  return "Harlequin";
        case  rabbit_breed::PALOMINO:   return "Palomino";
        case  rabbit_breed::SABLE:      return "Sable";
        case  rabbit_breed::ANGORA:     return "Angora";
        case  rabbit_breed::DWARF:      return "Dwarf";
        case  rabbit_breed::WOOLY:      return "Wooly";
        case  rabbit_breed::CHINCHILLA: return "Chinchilla";
        case  rabbit_breed::LIONHEAD:   return "Lionhead";
        default:                        return "UNKNOWN";
    }
}
std::ostream& operator<<(std::ostream& ost, const rabbit_breed& breed) {
    ost << ::to_string(breed);
    return ost;
}
