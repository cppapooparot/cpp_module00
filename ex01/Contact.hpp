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
        std::string darkest_secret;
    public:
        Contact();
        Contact(std::string name, std::string surname, std::string nickname,
            std::string phone_number, std::string darkest_secret);
    std::string get_name() const;
    std::string get_surname() const;
    std::string get_nickname() const;
    std::string get_phone_number() const;
    std::string get_darkest_secret() const;
};

#endif