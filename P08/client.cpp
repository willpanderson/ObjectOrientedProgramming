#include "client.h"

Client::Client(std::string name, Gender gender, int age)
    : _name{name}, _phone{phone}, _email{email} { }

std::ostream& operator<<(std::ostream& ost, const Client& client) {
    ost << to_string(client);
    return ost;
}
