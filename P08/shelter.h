#ifndef __SHELTER_H
#define __SHELTER_H

#include "animal.h"
#include "client.h"
#include <vector>

class Shelter {
  public:
    Shelter(std::string name);
    ~Shelter();
    std::string name();
    Shelter(std::istream& ist);
    void save(std::ostream& ost);
    std::string getFilename();
    void setFilename(std::string name);
    void add_animal(Animal& animal);
    int num_animals();
    Animal& animal(int index); 
    bool saved();
    void add_client(Client& client);
    int num_clients();
    Client& client(int index);
    bool dirty;
    void adopt(Client& client, Animal& animal);
    void undo_client();
    void undo_animal();
    std::string manage_role(int number);
    protected:
    std::string filename;

  private:
    std::string _name;
    std::vector<Animal*> _available;
    std::vector<Client>  _clients;
    std::string _role;
};

#endif

