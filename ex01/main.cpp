#include "Contact.hpp"
#include <iostream>

int main()
{
    Contact contact("Narek", "Sahakyan", "nsahakya", "+37498764430");
    std::cout << contact.get_name() << contact.get_surname() << contact.get_nickname() << contact.get_phone_number() << std::endl;
    return 0;
}