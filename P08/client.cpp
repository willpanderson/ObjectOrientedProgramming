#include "client.h"

Client::Client(std::string name, std::string phone, std::string email) : _name{name}, _phone{phone}, _email{email} { }

std::ostream& operator <<(std::ostream& ost, const Client& client) {
   ost << client.to_string();
   return ost;
}

std::string Client::to_string() const {
   std::string format = "";
   format += _name + '(' + _phone + ",  " + _email + ')';
   return format;
}


