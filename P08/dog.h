#ifndef __DOG_H_
#define __DOG_H_

#include "animal.h"

enum class Breed {Bloodhound, Rotwiler, Beagle, Pitbull, Bulldog, Chihuahua, Samoyed, Poodle};

class Dog : public Animal
{

public:
  Dog(Breed breed, std::string name, Gender gender, int age);
  ~Dog();
  std::string family() override;
  std::string breed()  override;

private:
  Breed _breed;

};


#endif
