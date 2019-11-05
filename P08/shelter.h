#ifndef __SHELTER_H_
#define __SHELTER_H_

#include "animal.h"
#include "dog.h"
#include <vector>

class Shelter
{

public:
  Shelter(std::string name);
  std::string name();
  void add_animal (Animal& animal);
  int num_animals();
  Animal& animal(int index);

private:
  std::string _name;
  std::vector <Animal*> _avalible;

};

#endif
