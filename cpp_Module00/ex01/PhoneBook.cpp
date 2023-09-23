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
	std::cin >> contacts[idx].first_name;
	while (!str_alpha(contacts[idx].first_name))
	{
		std::cout << "First name should contain only alphabet." << std::endl;
		std::cin >> contacts[idx].first_name;
	}
	std::cin >> contacts[idx].last_name;
	while (!str_alpha(contacts[idx].last_name))
	{
		std::cout << "Last name should contain only alphabet." << std::endl;
		std::cin >> contacts[idx].last_name;
	}
	std::cin >> contacts[idx].nickname;
	std::cin >> contacts[idx].phone_number;
	while (!str_digit(contacts[idx].phone_number))
	{
		std::cout << "Phone nubmer should contain only digit." << std::endl;
		std::cin >> contacts[idx].phone_number;
	}
	std::cin >> contacts[idx].darkest_secret;
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
		std::cout << get_new_str(contacts[i].first_name) << "|";
		std::cout << get_new_str(contacts[i].last_name) << "|";
		std::cout << get_new_str(contacts[i].nickname) << "|" << std::endl;
	}
	std::cout << "Choose one index to see more details." << std::endl;
	std::string idx;
	std::cin >> idx;
	while (!(idx == "1" || idx == "2" || idx == "3" || idx == "4" ||
				idx == "5" || idx =="6" || idx == "7" || idx == "8"))
	{
		std::cout << "Choose index between 1 ~ 8" << std::endl;
		std::cin >> idx;
	}
	std::cout << "****************************************" << std::endl;
	std::cout << "FIRST NAME : " << contacts[idx.front() - 49].first_name << std::endl;
	std::cout << "LAST NAME : " << contacts[idx.front() - 49].last_name << std::endl;
	std::cout << "NICKNAME : " << contacts[idx.front() - 49].nickname << std::endl;
	std::cout << "PHONE NUMBER : " << contacts[idx.front() - 49].phone_number << std::endl;
	std::cout << "DARKEST SECRET : " << contacts[idx.front() - 49].darkest_secret << std::endl;
	std::cout << "*****************************************" << std::endl;
}
