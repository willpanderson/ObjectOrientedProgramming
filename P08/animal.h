#ifndef __ANIMAL_H_
#define __ANIMAL_H_

#include "gender.h"
#include "dog_breed.h"

class Animal
{

public:
  void Animal(std::string name, Gender gender, int age);
  virtual ~Animal();
  virtual std::string family();
  virtual std::string breed();
  virtual std::string name();
  Gender gender();
  int age();
  std::string to_string();


protected:
  std::string _name;
  Gender _gender;
  int _age;
};


#endif
