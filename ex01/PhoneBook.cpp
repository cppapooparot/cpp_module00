#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() : nextIndex(0), count(0) {}

static void print_space(int num)
{
    for (int i = 0; i < num; i++)
        std::cout << " ";
}

static void print_table(Contact contact, size_t index)
{
    Contact trimmed_contact = contact.trim_contact();
    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    std::cout << "|";
    std::cout << "         " << index << "|";
    print_space(10 - trimmed_contact.get_name().size());
    std::cout << trimmed_contact.get_name() << "|";
    print_space(10 - trimmed_contact.get_surname().size());
    std::cout << trimmed_contact.get_surname() << "|";
    print_space(10 - trimmed_contact.get_nickname().size());
    std::cout << trimmed_contact.get_nickname() << "|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
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
    int i = index - 1;
    print_table(this->contacts[i], index);
}

int PhoneBook::get_count() {return this->count;}


