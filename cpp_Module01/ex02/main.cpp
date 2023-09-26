#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "*****MEMORY ADDRESS PRINT*****" << std::endl;
	std::cout << "string address: " << &str << std::endl;
	std::cout << "string pointer address: " << stringPTR << std::endl;
	std::cout << "string reference address: " << &stringREF << std::endl;

	std::cout << "*****VALUE PRINT *****" << std::endl;
	std::cout << "string value: " << str << std::endl;
	std::cout << "string pointer pointing value: " << *stringPTR << std::endl;
	std::cout << "string reference pointing value: " << stringREF << std::endl;

	return (0);
}
