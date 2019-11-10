#ifndef __CAT_H
#define __CAT_H

#include "animal.h"

// List of cat breeds, conversion to/from string and stream, and iteration
enum class cat_breed {
    BEAGLE,
    BOXER,
    BULLDOG,
    DACHSHUND,
    LABRADOR,
    MIX,
    POINTER,
    POODLE,
    RETRIEVER,
    ROTTWEILER,
    SHEPHERD,
    TERRIER,
};
constexpr cat_breed cat_breeds[] = {
    cat_breed::BEAGLE,
    cat_breed::BOXER,
    cat_breed::BULLDOG,
    cat_breed::DACHSHUND,
    cat_breed::LABRADOR,
    cat_breed::MIX,
    cat_breed::POINTER,
    cat_breed::POODLE,
    cat_breed::RETRIEVER,
    cat_breed::ROTTWEILER,
    cat_breed::SHEPHERD,
    cat_breed::TERRIER,
};
std::string to_string(const cat_breed& breed);
std::ostream& operator<<(std::ostream& ost, const Dog_breed& breed);

// Class Dog with overrides for family and breed
class Cat : public Animal {
  public:
    Cat(Cat_breed breed, std::string name, Gender gender, int age);
    virtual ~Cat();
    virtual std::string family() const override;
    virtual std::string breed() const override;
  private:
    Cat_breed _breed;
};

#endif
