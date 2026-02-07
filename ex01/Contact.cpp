#include "Contact.hpp"
#include <string>

Contact::Contact(std::string name, std::string surname, std::string nickname,
            std::string phone_number) : name(name), surname(surname), nickname(nickname), phone_number(phone_number)
{}

std::string Contact::get_name() {return this->name; }
std::string Contact::get_surname() {return this->surname; }
std::string Contact::get_nickname() {return this->nickname; }
std::string Contact::get_phone_number() {return this->phone_number; }