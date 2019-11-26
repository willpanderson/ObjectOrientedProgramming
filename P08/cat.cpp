#include "cat.h"
#include <sstream>
// Constructor / Destructor - note how delegation to base class works!
Cat::Cat(cat_breed breed, std::string name, Gender gender, int age)
    : Animal(name, gender, age), _breed{breed} { }
Cat::~Cat() { }

// Overrides for pure virtual methods
std::string Cat::family() const {return "cat";}
std::string Cat::breed() const {return ::to_string(_breed);}

std::string to_string(const cat_breed& breed)
{
  std::map<cat_breed, std::string> breeds = {
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

std::ostream& operator<<(std::ostream& ost, const cat_breed& breed) {
    ost << ::to_string(breed);
    return ost;
}

void Cat::save(std::ostream& ost)
{
  ost << family();
  ost << _name;
  ost << _gender;
  ost << _age;
  ost << _breed << std::endl;
}

//Cat::Cat(std::istream& ist) : Animal(ist)
//{
  //ist >> breed;
  //Animal(ist);
//}
