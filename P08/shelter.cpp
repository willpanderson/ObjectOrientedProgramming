#include "shelter.h"


Shelter::Shelter(std::string name) : _name{name} { }
std::string Shelter::name() {return _name;}

void Shelter::add_animal(Animal& animal) {
    _available.push_back(&animal);
}
int Shelter::num_animals() {return _available.size();}
Animal& Shelter::animal(int index) {return *(_available[index]);}

void Shelter::add_client(Client& client) {
    _clients.push_back(client);
}
int Shelter::num_clients() {return _clients.size();}
Client& Shelter::client(int index) {return _clients[index];}

void Shelter::adopt(Client& client, Animal& animal) {
    client.adopt(animal);
    auto index = std::find(_available.begin(), _available.end(), &animal);
    if (index != _available.end()) _available.erase(index);
}

std::string Shelter::get_filename() {return filename;}
void Shelter::set_filename(std::string filename) {this->filename = filename;}

void Shelter::save(std::ostream& ost)
{
  ost << _name << "\n";

 for (auto a : _available)
 {
   a->save(ost);
 }
 ost << "\n";
 for (auto b : _clients)
 {
   b.save(ost);
 }
 ost << "\n";
}
/*
Shelter::Shelter(std::istream& ist)
{
  ist >> _name;
  int X;
  ist >> X
  for (int i = 0; i < N; i++)
  {
    std::string data;
    ist >> data;
    Animal *a;
  if (data == "dog")
  {
    a = new Dog(ist);
  }
  else if (data == "cat")
  {
    a = new Cat(ist);
  }
  else if (data == "rabbit")
  {
    a = new Rabbit(ist);
}
}
*/
