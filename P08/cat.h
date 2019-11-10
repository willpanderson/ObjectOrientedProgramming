#ifndef __CAT_H
#define __CAT_H

#include "animal.h"

// List of cat breeds, conversion to/from string and stream, and iteration
enum class cat_breed {
    SHORTHAIR,
    BOMBAY,
    PERSIAN,
    BENGAL,
    SPHYNX,
    BURMESE,
    BOBTAIL,
    MAU,
    LYKOI,
    KORAT,
    MANX,
    SIAMESE,
};
constexpr cat_breed cat_breeds[] = {
    cat_breed::SHORTHAIR,
    cat_breed::BOMBAY,
    cat_breed::PERSIAN,
    cat_breed::BENGAL,
    cat_breed::SPHYNX,
    cat_breed::BURMESE,
    cat_breed::BOBTAIL,
    cat_breed::MAU,
    cat_breed::LYKOI,
    cat_breed::KORAT,
    cat_breed::MANX,
    cat_breed::SIAMESE,
};
std::string to_string(const cat_breed& breed);
std::ostream& operator<<(std::ostream& ost, const cat_breed& breed);

// Class Dog with overrides for family and breed
class Cat : public Animal {
  public:
    Cat(Cat_breed breed, std::string name, Gender gender, int age);
    virtual ~Cat();
    virtual std::string family() const override;
    virtual std::string breed() const override;
  private:
    cat_breed _breed;
};

#endif
