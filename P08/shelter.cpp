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

void Shelter::adopt(Client& client,Animal& animal) {
 int index = -1;
/*animals might have the same name,breed,gender,family, and age so
//we will have to check each aspect to ensure that the right animal is removed */
 for (int i = 0; i < _available.size(); i++)
 {
  if (_available[i]->name() == animal.name()){
    if (_available[i]->family() == animal.family()){
      if (_available[i]->breed() == animal.breed()){
        if (_available[i]->gender() == animal.gender()){
            index = i;
	}
     }
   }
  }
 }
 client.adopt(animal);
 this->_available.erase(_available.begin()+index);
}

std::string Shelter::get_filename() {return filename;}
void Shelter::set_filename(std::string filename) {this->filename = filename;}

void Shelter::save(std::ostream& ost)
 {
   ost << Shelter->name() << ' ';
   for (int i = 0; i < num_clients(); i++)
    {
      ost << Shelter->animal(i) << ' ';
    }
  for (int j = 0; j < num_clients; j++)
    {
      ost << Shelter->client(i) << ' ';
    }
  }

void Shelter::load(std::istream& ist)
{
  //bool was_dirty = (shapes.size() > 0);
  //while(ist) {
    //  std::string typetag;
  //}
}
