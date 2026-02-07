#ifndef CONTACT
#define CONTACT

#include <string>
#include <cctype>

class Contact
{
    private:
        std::string name;
        std::string surname;
        std::string nickname;
        std::string phone_number;
    public:
        Contact(std::string name, std::string surname, std::string nickname,
            std::string phone_number);
        std::string get_name();
        std::string get_surname();
        std::string get_nickname();
        std::string get_phone_number();
};

#endif