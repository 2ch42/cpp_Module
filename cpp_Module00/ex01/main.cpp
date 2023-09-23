#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	std::cout << "Phonebook program launched!" << std::endl;
	std::cout << "You are allowed to three commands - ADD, SEARCH, EXIT!" << std::endl;
	int count = 0;
	PhoneBook phonebook;
	while (1)
	{
		std::string cmd;
		std::cin >> cmd;
		if (cmd == "ADD")
			phonebook.add(count++);
		else if (cmd == "SEARCH")
			phonebook.search();
		else if (cmd == "EXIT")
			break;
		count %= 8;
	}
	return (0);
}
