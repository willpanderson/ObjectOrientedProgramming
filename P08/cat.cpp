#include "cat.h"

// Constructor / Destructor - note how delegation to base class works!
Cat::Cat(cat_breed breed, std::string name, Gender gender, int age)
    : Animal(name, gender, age), _breed{breed} { }
Cat::~Cat() { }

// Overrides for pure virtual methods
std::string Cat::family() const {return "Albyssian";}
std::string Cat::breed() const {return ::to_string(_breed);}

// Convert breed to string and stream - use a std::map for other derived classes!
std::string to_string(const cat_breed& breed) {
    switch(breed) {
        case  cat_breed::SHORTHAIR:  return "Shorthair";
        case  cat_breed::BOMBAY:     return "Bombay";
        case  cat_breed::PERSIAN:    return "Persian";
        case  cat_breed::BENGAL:     return "Bengal";
        case  cat_breed::SPHYNX:     return "Sphynx";
        case  cat_breed::BURMESE:    return "Burmese";
        case  cat_breed::BOBTAIL:    return "Bobtail";
        case  cat_breed::MAU:        return "Mau";
        case  cat_breed::LYKOI:      return "Lykoi";
        case  cat_breed::KORAT:      return "Korat";
        case  cat_breed::MANX:       return "Manx";
        case  cat_breed::SIAMESE:    return "Siamese";
        default:                     return "UNKNOWN";
    }
}
std::ostream& operator<<(std::ostream& ost, const cat_breed& breed) {
    ost << ::to_string(breed);
    return ost;
}
