#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>

static bool check_instruction(std::string instruction)
{
    if (instruction == "ADD" || instruction == "SEARCH" || instruction == "EXIT")
        return true;
    std::cout << "Wrong command!" << std::endl;
    return false;
}

static bool is_alpha_string(const std::string& s)
{
    if (s.empty())
        return false;
    if (!std::isupper(static_cast<unsigned char>(s[0])))
        return false;
    for (size_t i = 1; i < s.size(); ++i)
    {
        unsigned char ch = static_cast<unsigned char>(s[i]);
        if (!std::islower(ch))
            return false;
    }
    return true;
}

static bool check_name_surname(const std::string& str)
{
    if (str.empty())
    {
        std::cerr << "The first name or the second name can't be empty!" << std::endl;
        return false;
    }
    unsigned char first = static_cast<unsigned char>(str[0]);
    if (!(first >= 'A' && first <= 'Z'))
    {
        std::cerr << "The first letter must be capital" << std::endl;
        return false;
    }
    if (!is_alpha_string(str))
    {
        std::cerr << "This field must contain only letters (first latter must be uppercase, others must be lowercase)" << std::endl;
        return false;
    }
    return true;
}

static bool check_phone_number(const std::string& phone_number)
{
    if (phone_number.empty())
    {
        std::cerr << "Phone number can't be empty!" << std::endl;
        return false;
    }

    size_t i = 0;
    if (phone_number[0] == '+')
        i = 1;

    if (i == phone_number.size())
    {
        std::cerr << "Phone number must contain digits after '+'" << std::endl;
        return false;
    }

    for (; i < phone_number.size(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(phone_number[i])))
        {
            std::cerr << "Phone number must contain only digits (optionally starting with '+')." << std::endl;
            return false;
        }
    }
    return true;
}

static bool check_not_empty(const std::string& s, const char* err)
{
    if (s.empty())
    {
        std::cerr << err << std::endl;
        return false;
    }
    return true;
}

static std::string prompt_token(const std::string& prompt)
{
    std::cout << prompt << std::endl;
    std::string s;
    if (!std::getline(std::cin, s))
    {
        if (std::cin.eof())
        {
            std::cerr << "Input closed." << std::endl;
            std::exit(EXIT_SUCCESS);
        }
        std::cin.clear();
        return std::string();
    }
    return s;
}
typedef bool (*ValidatorFn)(const std::string&);

static std::string prompt_until_valid(const std::string& prompt, ValidatorFn validate)
{
    while (true)
    {
        std::string s = prompt_token(prompt);
        if (validate(s))
            return s;
    }
}

static bool check_nickname(const std::string& s)
{
    return check_not_empty(s, "The nickname can't be empty!");
}

static bool check_darkest_secret(const std::string& s)
{
    return check_not_empty(s, "The darkest secret can't be empty!");
}

static bool add(PhoneBook& pb)
{
    std::cout << "This is your N" << pb.get_count() + 1 << " contact" << std::endl;

    std::string name = prompt_until_valid("Enter the first name", &check_name_surname);
    std::string surname = prompt_until_valid("Enter the second name", &check_name_surname);

    std::string nickname = prompt_until_valid("Enter the nickname", &check_nickname);

    std::string phone_number = prompt_until_valid("Enter the phone number", &check_phone_number);

    std::string darkest_secret = prompt_until_valid("Enter the darkest secret", &check_darkest_secret);

    Contact contact(name, surname, nickname, phone_number, darkest_secret);
    pb.add(contact);
    return true;
}

static bool search(PhoneBook& pb)
{
    if (pb.get_count() == 0)
    {
        std::cerr << "PhoneBook is empty. Use ADD first." << std::endl;
        return false;
    }

    pb.print_contacts();

    while (true)
    {
        std::cout << "Enter index of the contact (1-" << pb.get_count() << ")" << std::endl;

        int index;
        if (std::cin.peek() == '\n')
            std::cin.get();
        if (!(std::cin >> index))
        {
            if (std::cin.eof())
            {
                std::cerr << "Input closed." << std::endl;
                return false;
            }
            std::cin.clear();
            std::string junk;
            std::getline(std::cin, junk);
            std::cerr << "Please enter a number." << std::endl;
            continue;
        }
        std::string rest;
        std::getline(std::cin, rest);

        if (index < 1 || index > pb.get_count())
        {
            std::cerr << "Invalid index. Try again." << std::endl;
            continue;
        }

    pb.print_contact_details(static_cast<size_t>(index));
        return true;
    }
}

int main()
{
    PhoneBook pb;
    std::string instruction;

    while (true)
    {
        std::cout << "Enter your command [ADD, SEARCH, EXIT]:" << std::endl;
        if (!std::getline(std::cin, instruction))
        {
            std::cerr << "Input closed." << std::endl;
            break;
        }
        if (instruction.empty())
            continue;

        if (!check_instruction(instruction))
            continue;

        if (instruction == "ADD")
        {
            if (add(pb))
                std::cout << "The contact was saved successfully" << std::endl;
        }
        else if (instruction == "SEARCH")
        {
            search(pb);
        }
        else if (instruction == "EXIT")
        {
            break;
        }
    }
    return 0;
}