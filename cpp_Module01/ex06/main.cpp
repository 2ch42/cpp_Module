#include "Harl.hpp"

int	arg_to_num(char *argv)
{
	std::string s(argv);
	std::string str_arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (s == str_arr[i])
		{
			return (i);
		}
	}
	return (-1);
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
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("DEBUG");
			std::cout << "\n";
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("INFO");
			std::cout << "\n";
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("WARNING");
			std::cout << "\n";
		case 3:
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
