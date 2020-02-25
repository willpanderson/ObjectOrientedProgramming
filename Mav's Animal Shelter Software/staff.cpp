#include "staff.h"
#include <map>


// Convert staff to string and stream - use a std::map for other derived classes!
std::string to_string(const Staff_Type& staff) {
    std::map<Staff_Type,std::string> staff_map {
        { Staff_Type::STAFF,  "Staff"}, 
        { Staff_Type::MANAGER,  "Manager"},
        { Staff_Type::DIRECTOR,  "Director"}, 
       
    };
    try {
        return staff_map.at(staff);
    } catch (std::exception& e) {
        return "Unknown";
    }
}
// Constructor / Destructor
Staff::Staff(std::string name, std::string phone, std::string email, double salary, std::string username, std::string password, bool active, Staff_Type role)
    : Client(name,phone,email), _salary{salary} ,_username{username}, _password{password}, _active{active},_role{role} { }
Staff::~Staff() {} 


// Streaming I/O
std::ostream& operator<<(std::ostream& ost, const Staff& staff) {
    ost << staff._name  << " ("
        << staff._phone << ", "
        << staff._email << ')';
    return ost;
}


