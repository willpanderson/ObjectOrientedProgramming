#ifndef __CLIENT_H
#define __CLIENT_H

#include <string>

std::ostream& operator<<(std::ostream& ost, const Client& client);


class Client {
  public:
    Client(std::string name, std::string phone, std::string email);

  private:
    std::string _name;
    std::string _phone;
    std::string _email;
};

#endif
