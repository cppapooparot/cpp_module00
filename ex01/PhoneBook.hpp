#ifndef H_PHONEBOOK
#define H_PHONEBOOK

#define MAX_CONTACT 8
#//include <string>
#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[MAX_CONTACT];
        int nextIndex;
        int count;

        void trim_contact();
    public:
        PhoneBook();
        bool add(Contact contact);
        void search(size_t index);
        void exit();
        int get_count();
};

#endif