#ifndef __STAFF_H
#define __STAFF_H

#include "client.h"
#include <string>
#include <vector>


class Staff : public Client {
  public:
  Staff(std::string name, std::string email, std::string phone);
  ~Staff();
  Staff(std::istream& ist);
  void manage_staff;
  void save(std::ostream& ost);

  friend std::ostream& operator<<(std::ostream& ost, const Staff& staff);

  private:
    std::string _name;
    std::string _email;
    std::string _phone;
    double _salary;
    std::string _password;
    bool _active = true;
};

#endif
