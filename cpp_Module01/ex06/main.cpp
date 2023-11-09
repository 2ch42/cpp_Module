#include "Harl.hpp"

int	arg_to_num(char *argv)
{
	std::string s(argv);
	if (s == "DEBUG")
		return (1);
	else if (s == "INFO")
		return (2);
	else if (s == "WARNING")
		return (3);
	else if (s == "ERROR")
		return (4);
	else
		return (0);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error!" << std::endl;
		return (0);
	}
	Harl	harl;

	switch (arg_to_num(argv[1]))
	{
		case 1:
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("DEBUG");
			std::cout << "\n";
		case 2:
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("INFO");
			std::cout << "\n";
		case 3:
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("WARNING");
			std::cout << "\n";
		case 4:
			std::cout << "[ ERROR ]" << std :: endl;
			harl.complain("ERROR");
			std::cout << "\n";
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			std::cout << "\n";
	}

	return (0);
}
