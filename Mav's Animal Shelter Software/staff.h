#ifndef __STAFF_H
#define __STAFF_H

#include "client.h"
#include <string>
#include <vector>

enum class Staff_Type {
    MANAGER,
    STAFF,
    DIRECTOR,
};

constexpr Staff_Type type_staff[] = {
    Staff_Type::MANAGER,
    Staff_Type::STAFF,
    Staff_Type::DIRECTOR,
};


class Staff : public Client {
  public:
  Staff(std::string name, std::string email, std::string phone, double salary, std::string username, std::string password, bool active, Staff_Type role);
  ~Staff();
  std::string to_string(const Staff_Type& staff);
  friend std::ostream& operator<<(std::ostream& ost, const Staff& staff);

  private:
    std::string _name;
    std::string _email;
    std::string _phone;
    double _salary;
    std::string _username;
    std::string _password;
    bool _active;
    Staff_Type _role;
};

#endif
