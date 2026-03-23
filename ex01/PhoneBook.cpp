#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>

PhoneBook::PhoneBook() : nextIndex(0), count(0) {}

static std::string format_column(const std::string& s)
{
    if (s.size() > 10)
        return s.substr(0, 9) + ".";
    return s;
}

bool PhoneBook::add(Contact contact)
{
    this->contacts[this->nextIndex] = contact;
    this->nextIndex = (this->nextIndex + 1) % MAX_CONTACT;

    if (this->count < MAX_CONTACT)
        this->count++;
    return true;
}


void PhoneBook::search(size_t index)
{
    this->print_contact_details(index);
}

void PhoneBook::print_contacts() const
{
    std::cout << std::setw(10) << "index" << "|"
              << std::setw(10) << "first name" << "|"
              << std::setw(10) << "last name" << "|"
              << std::setw(10) << "nickname" << std::endl;

    for (int i = 0; i < this->count; ++i)
    {
        const Contact& c = this->contacts[i];
        std::cout << std::setw(10) << (i + 1) << "|"
                  << std::setw(10) << format_column(c.get_name()) << "|"
                  << std::setw(10) << format_column(c.get_surname()) << "|"
                  << std::setw(10) << format_column(c.get_nickname())
                  << std::endl;
    }
}

void PhoneBook::print_contact_details(size_t index) const
{
    if (index < 1 || index > static_cast<size_t>(this->count))
        return;
    const Contact& c = this->contacts[index - 1];
    std::cout << "First name: " << c.get_name() << std::endl;
    std::cout << "Last name: " << c.get_surname() << std::endl;
    std::cout << "Nickname: " << c.get_nickname() << std::endl;
    std::cout << "Phone number: " << c.get_phone_number() << std::endl;
    std::cout << "Darkest secret: " << c.get_darkest_secret() << std::endl;
}

int PhoneBook::get_count() {return this->count;}


