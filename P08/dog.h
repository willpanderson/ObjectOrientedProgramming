#ifndef __DOG_H_
#define __DOG_H_

#include "animal.h"


class Dog : public Animal
{

public:
  void Dog(std::string name, Gender gender, int age);
  virtual ~Dog();
  std::string family(); override
  std::string breed(); override

private:
  int _breed;

};


#endif
