#ifndef __RABBIT_H
#define __RABBIT_H

#include "animal.h"

// List of cat breeds, conversion to/from string and stream, and iteration
enum class rabbit_breed {
    HARE, //0
    GIANT, //1
    FUZZY, //2
    GOTLAND,
    HARLEQUIN,
    PALOMINO,
    SABLE,
    ANGORA,
    DWARF,
    WOOLY,
    CHINCHILLA,
    LIONHEAD,
};
constexpr rabbit_breed rabbit_breeds[] = {
    rabbit_breed::HARE,
    rabbit_breed::GIANT,
    rabbit_breed::FUZZY,
    rabbit_breed::GOTLAND,
    rabbit_breed::HARLEQUIN,
    rabbit_breed::PALOMINO,
    rabbit_breed::SABLE,
    rabbit_breed::ANGORA,
    rabbit_breed::DWARF,
    rabbit_breed::WOOLY,
    rabbit_breed::CHINCHILLA,
    rabbit_breed::LIONHEAD,
};
std::string to_string(const rabbit_breed& breed);
std::ostream& operator<<(std::ostream& ost, const rabbit_breed& breed);

// Class Dog with overrides for family and breed
class Rabbit : public Animal {
  public:
    Rabbit(rabbit_breed breed, std::string name, Gender gender, int age);
    virtual ~Rabbit();
    virtual std::string family() const override;
    virtual std::string breed() const override;
    virtual void save(std::ostream& ost) override;
    Rabbit(std::istream& ist);

  private:
    rabbit_breed _breed;
};

#endif
