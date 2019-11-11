#include "rabbit.h"

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
  {
  std::map<rabbit_breed, std::string> breeds = {
      {cat_breed::SHORTHAIR, "Shorthair"},
      {cat_breed::BOMBAY, "Bombay"},
      {cat_breed::PERSIAN, "Persian"},
      {cat_breed::BENGAL, "Bengal"},
      {cat_breed::SPHYNX, "Sphynx"},
      {cat_breed::BURMESE, "Burmese"},
      {cat_breed::BOBTAIL, "Bobtail"},
      {cat_breed::MAU, "Mau"},
      {cat_breed::LYKOI, "Lykoi"},
      {cat_breed::KORAT, "Korat"},
      {cat_breed::MANX, "Manx"},
      {cat_breed::SIAMESE, "Siamese"},
  };

	return breeds[breed];
 
}
 
std::ostream& operator<<(std::ostream& ost, const rabbit_breed& breed) {
    ost << ::to_string(breed);
    return ost;
}
