#include <iomanip>
#include <string>
#include "PhoneBook.hpp"

int	str_digit(std::string str)
{
	int i = 0;
	while (i < str.size())
	{
		if (!(str[i] <= '9' && str[i] >= '0'))
			return (0);
		i++;
	}
	return (1);
}

int	str_alpha(std::string str)
{
	int i = 0;
	while (i < str.size())
	{
		if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
			return (0);
		i++;
	}
	return (1);
}	

std::string	get_new_str(std::string str)
{
	std::string new_str;

	if (str.size() > 10)
	{
		new_str = str.substr(0, 9);
		new_str += ".";
		return (new_str);
	}
	else if (str.size() < 10)
	{
		int i = 0;
		while (i++ < 10 - str.size())
			new_str += " ";
		new_str += str;
		return (new_str);
	}
	return (str);
}

void	PhoneBook::add(int idx)
{
	std::cout << "You are now adding a single contact to phonebook!" << std::endl;
	std::cout <<"You need to fill first name, last name, nickname, phone number, and darkest secret!" << std::endl;
	std::cout << "No empty field allowed!" << std:: endl;
	std::cout << "Thus, fill phone number without \'-\' " << std::endl;

	std::string first_name;
	std::cin >> first_name;
	if (std::cin.eof())
		std::exit(1);
	while (!str_alpha(first_name))
	{
		std::cout << "First name should contain only alphabet." << std::endl;
		std::cin >> first_name;
		if (std::cin.eof())
			std::exit(1);
	}
	contacts[idx].set_first_name(first_name);

	std::string last_name;
	std::cin >> last_name;
	if (std::cin.eof())
		std::exit(1);
	while (!str_alpha(last_name))
	{
		std::cout << "Last name should contain only alphabet." << std::endl;
		std::cin >> last_name;
		if (std::cin.eof())
			std::exit(1);
	}
	contacts[idx].set_last_name(last_name);

	std::string nickname;
	std::cin >> nickname;
	if (std::cin.eof())
		std::exit(1);
	contacts[idx].set_nickname(nickname);

	std::string phone_number;
	std::cin >> phone_number;
	if (std::cin.eof())
		std::exit(1);
	while (!str_digit(phone_number))
	{
		std::cout << "Phone number should contain only digit." << std::endl;
		std::cin >> phone_number;
		if (std::cin.eof())
			std::exit(1);
	}
	contacts[idx].set_phone_number(phone_number);

	std::string darkest_secret;
	std::cin >> darkest_secret;
	if (std::cin.eof())
		std::exit(1);
	contacts[idx].set_darkest_secret(darkest_secret);
	
	std::cout << "New contact added successfully!" << std::endl;
}

void	PhoneBook::search(void)
{
	for(int i = 0; i < 8; i++)
	{
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << i + 1;
		std::cout << "|";
		std::cout << get_new_str(contacts[i].get_first_name()) << "|";
		std::cout << get_new_str(contacts[i].get_last_name()) << "|";
		std::cout << get_new_str(contacts[i].get_nickname()) << "|" << std::endl;
	}
	std::cout << "Choose one index to see more details." << std::endl;
	std::string idx;
	std::cin >> idx;
	if (std::cin.eof())
		std::exit(1);
	while (!(idx == "1" || idx == "2" || idx == "3" || idx == "4" ||
				idx == "5" || idx =="6" || idx == "7" || idx == "8"))
	{
		std::cout << "Choose index between 1 ~ 8" << std::endl;
		std::cin >> idx;
		if (std::cin.eof())
			std::exit(1);
	}
	std::cout << "****************************************" << std::endl;
	std::cout << "FIRST NAME : " << contacts[idx.front() - 49].get_first_name() << std::endl;
	std::cout << "LAST NAME : " << contacts[idx.front() - 49].get_last_name() << std::endl;
	std::cout << "NICKNAME : " << contacts[idx.front() - 49].get_nickname() << std::endl;
	std::cout << "PHONE NUMBER : " << contacts[idx.front() - 49].get_phone_number() << std::endl;
	std::cout << "DARKEST SECRET : " << contacts[idx.front() - 49].get_darkest_secret() << std::endl;
	std::cout << "*****************************************" << std::endl;
}
