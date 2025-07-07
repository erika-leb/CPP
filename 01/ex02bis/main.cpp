#include <iostream>

int	main(void)
{
	std::string str;
	std::string *stringPTR;
	std::string &sringREF = str;

	str = "HI THIS IS BRAIN";
	stringPTR = &str;
	std::cout << "MEMORY ADRESSES" << std::endl;
	std::cout << "Memory address of the string variable: " << &str <<std::endl;
	std::cout << "Memory address of the string pointer: " << &stringPTR <<std::endl;
	std::cout << "Memory address of the string reference: " << &sringREF <<std::endl;
	std::cout << "VALUES" << std::endl;
	std::cout << "Value of the string variable: " << str << std::endl;
	std::cout << "Value of the string pointer: " << *stringPTR << std::endl;
	std::cout << "Value of the string reference: " << sringREF  << std::endl;
	return (0);
}

