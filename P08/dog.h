#ifndef __DOG_H_
#define __DOG_H_

class Dog
{

public:
  void Dog(std::string name, Gender gender, Gender age,int age);
  void ~Dog();
  void family();
  void breed();

private:
  int _breed;
};


#endif
