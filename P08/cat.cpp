#include "cat.h"

// Constructor / Destructor - note how delegation to base class works!
Cat::Cat(cat_breed breed, std::string name, Gender gender, int age)
    : Animal(name, gender, age), _breed{breed} { }
Cat::~Cat() { }

// Overrides for pure virtual methods
std::string Cat::family() const {return "Albyssian";}
std::string Cat::breed() const {return ::to_string(_breed);}

std::map<cat_breed breed, std::string> breeds = {
    {cat_breed::SHORTHAIR, "Shorthair"},
    {cat_breed::BOMBAY, "Bombay"},
    {cat::breed::BENGAL, "Persian"},
    {cat::breed::SPHYNX, "Sphynx"},
    {cat::breed::BURMESE, "Burmese"},
    {cat::breed::BOBTAIL, "Bobtail"},
    {cat::breed::MAU, "Mau"},
    {cat::breed::LYKOI, "Lykoi"},
    {cat::breed::KORAT, "Korat"},
    {cat::breed::MANX, "Manx"},
    {cat::breed::SIAMESE, "Siamese"},

};

std::ostream& operator<<(std::ostream& ost, const auto& [breed, string] breed) {
    ost << ::to_string(breed);
    return ost;
}
