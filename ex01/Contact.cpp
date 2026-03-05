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

std::string Contact::get_name() { return this->name; }
std::string Contact::get_surname() { return this->surname; }
std::string Contact::get_nickname() { return this->nickname; }
std::string Contact::get_phone_number() { return this->phone_number; }

Contact Contact::trim_contact()
{
    Contact trimmed_contact = *this;
    if (this->name.size() > 10)
        trimmed_contact.name = this->name.substr(0, 9) + '.';
    if (this->surname.size() > 10)
        trimmed_contact.surname = this->surname.substr(0, 9) + '.';
    if (this->nickname.size() > 10)
        trimmed_contact.nickname = this->nickname.substr(0, 9) + '.';
    if (this->phone_number.size() > 10)
        trimmed_contact.phone_number = this->phone_number.substr(0, 9) + '.';
    if (this->darkest_secret.size() > 10)
        trimmed_contact.darkest_secret = this->darkest_secret.substr(0, 9) + '.';
    return trimmed_contact;
}

