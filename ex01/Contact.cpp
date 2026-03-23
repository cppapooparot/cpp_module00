#include "Contact.hpp"
#include <string>

Contact::Contact() {}

Contact::Contact(std::string name, std::string surname, std::string nickname,
                 std::string phone_number, std::string darkest_secret)
    : name(name),
      surname(surname),
      nickname(nickname),
      phone_number(phone_number),
      darkest_secret(darkest_secret)
{
}

std::string Contact::get_name() const { return this->name; }
std::string Contact::get_surname() const { return this->surname; }
std::string Contact::get_nickname() const { return this->nickname; }
std::string Contact::get_phone_number() const { return this->phone_number; }
std::string Contact::get_darkest_secret() const { return this->darkest_secret; }