#ifndef H_PHONEBOOK
#define H_PHONEBOOK

#define MAX_CONTACT 8
#include <cstddef>
#include <iostream>
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
    void search(size_t index);
    void print_contacts() const;
    void print_contact_details(size_t index) const;
        int get_count();
};

#endif