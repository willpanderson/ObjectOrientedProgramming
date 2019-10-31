#ifndef __SHELTER_H_
#define __SHELTER_H_

class Shelter
{

public:
  void Shelter(std::string name);
  void ~Animal();
  std::string name();
  void add_animal (Animal& animal);
  int num_animals();
  Animal& animal(int index);

private:
  std::string _name;
  std::vector <Animal*> _avalible;

};

#endif
