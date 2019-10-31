#ifndef __ANIMAL_H_
#define __ANIMAL_H_

class Animal
{

public:
  void Animal(std::string name, Gender gender, Gender age,int age);
  void ~Animal();
  std::string family();
  std::string breed();
  std::string name();
  Gender gender();
  int age();
  std::string to_string();


protected:
  std::string _name;
  Gender gender;
  int _age;
};


#endif
