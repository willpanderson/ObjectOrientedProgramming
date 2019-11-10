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
        case  rabbit_breed::SHORTHAIR:  return "Shorthair";
        case  rabbit_breed::BOMBAY:     return "Giant";
        case  rabbit_breed::PERSIAN:    return "Fuzzy";
        case  rabbit_breed::BENGAL:     return "Gotland";
        case  rabbit_breed::SPHYNX:     return "Harlequin";
        case  rabbit_breed::BURMESE:    return "Palomino";
        case  rabbit_breed::BOBTAIL:    return "Sable";
        case  rabbit_breed::MAU:        return "Angora";
        case  rabbit_breed::LYKOI:      return "Dwarf";
        case  rabbit_breed::KORAT:      return "Wooly";
        case  rabbit_breed::MANX:       return "Chinchilla";
        case  rabbit_breed::SIAMESE:    return "Lionhead";
        default:                        return "UNKNOWN";
    }
}
std::ostream& operator<<(std::ostream& ost, const rabbit_breed& breed) {
    ost << ::to_string(breed);
    return ost;
}
