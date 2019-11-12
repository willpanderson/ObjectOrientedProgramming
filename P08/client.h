#ifndef __CLIENT_H
#define __CLIENT_H

#include <string>
#include <ostream>


class Client {
  public:
    Client(std::string name, std::string phone, std::string email);
    friend std::ostream& operator<<(std::ostream& ost, const Client& client);
    virtual std::string to_string() const;

  private:
    std::string _name;
    std::string _phone;
    std::string _email;
};



    


#endif
