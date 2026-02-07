#ifndef H_PHONEBOOK
#define H_PHONEBOOK

#include <string>
#define MAX_CONTACT 8
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[MAX_CONTACT];
        int nextIndex;
        int count;
    public:
        PhoneBook();
        bool add(Contact contact);
        std::string search(int index);
        void exit();
};

#endif