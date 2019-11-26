#ifndef __SHELTER_H
#define __SHELTER_H

#include "animal.h"
#include "client.h"
#include <vector>

class Shelter {
  public:
    Shelter(std::string name);
    std::string name();
    void add_animal(Animal& animal);
    int num_animals();
    Animal& animal(int index);
    void add_client(Client& client);
    int num_clients();
    Client& client(int index);
    void adopt(Client& client, Animal& animal);
    std::string get_filename();
    void set_filename(std::string filename);
    //bool saved(); // true if all data has been saved
    void save(std::ostream& ost);
  //  Shelter(std::istream& ist);
protected:
   std::string filename;

  private:
    std::string _name;
    std::vector<Animal*> _available;
    std::vector<Client> _clients;
};

#endif
