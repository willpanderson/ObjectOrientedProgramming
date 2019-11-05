#ifndef __ANIMAL_H_
#define __ANIMAL_H_

#include <string>


enum class Gender{Male, Female,count};

class Animal
{

public:
  Animal(std::string name, Gender gender, int age);
  ~Animal();
  virtual std::string family() = 0;
  virtual std::string breed() = 0;
  std::string name();
  Gender gender();
  int age();
  std::string to_string();


protected:
  std::string _name;
  Gender _gender;
  int _age;
};
#endif
