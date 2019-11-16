#ifndef __CLIENT_H
#define __CLIENT_H

#include <string>
#include <ostream>
#include "animal.h"
#include <vector>

class Client {
  public:
    Client(std::string name, std::string phone, std::string email);
    friend std::ostream& operator<<(std::ostream& ost, const Client& client);
    virtual std::string to_string() const;
    Animal& animal(int index) const;

  private:
    std::string _name;
    std::string _phone;
    std::string _email;
    std::vector <Animal *> _adopted;
};






#endif
