#ifndef __DOG_H_
#define __DOG_H_

#include "animal.h"
#include "dog_breed.h"
#include <string>

class Dog : public Animal
{

public:
  Dog(Breed breed, std::string name, Gender gender, int age);
  ~Dog();
  std::string family(); 
  std::string breed(); 

private:
  int _breed;

};


#endif
