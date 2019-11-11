#include "cat.h"
#include <sstream>
// Constructor / Destructor - note how delegation to base class works!
Cat::Cat(cat_breed breed, std::string name, Gender gender, int age)
    : Animal(name, gender, age), _breed{breed} { }
Cat::~Cat() { }

// Overrides for pure virtual methods
std::string Cat::family() const {return "Albyssian";}
std::string Cat::breed() const {return ::to_string(_breed);}

std::string to_string(const cat_breed& breed)
{
  std::map<cat_breed, std::string>::iterator it;
  std::map<cat_breed, std::string> breeds = {
      {cat_breed::SHORTHAIR, "Shorthair"},
      {cat_breed::BOMBAY, "Bombay"},
      {cat_breed::BENGAL, "Persian"},
      {cat_breed::SPHYNX, "Sphynx"},
      {cat_breed::BURMESE, "Burmese"},
      {cat_breed::BOBTAIL, "Bobtail"},
      {cat_breed::MAU, "Mau"},
      {cat_breed::LYKOI, "Lykoi"},
      {cat_breed::KORAT, "Korat"},
      {cat_breed::MANX, "Manx"},
      {cat_breed::SIAMESE, "Siamese"},
  };
  //it = breeds.find(breed);
  //if (it != breeds.end())
  //{
    //breeds.erase(it);
  //}

  std::ostringstream ost;
  //ost << breeds.find(breed)->second << "\n";
  return ost.str();
}

std::ostream& operator<<(std::ostream& ost, const cat_breed& breed) {
    ost << ::to_string(breed);
    return ost;
}
