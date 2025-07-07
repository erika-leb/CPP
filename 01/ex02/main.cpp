# include <iostream>

int	main(void)
{
	std::string	str;
	std::string	*stringPTR;
	std::string	&stringREF = str;

	str = "HI THIS IS BRAIN";
	stringPTR = &str;
	std::cout << "MEMORY ADRESSES" << std::endl;
	std::cout << "Memory adress of the string variable: " << &str << std::endl;
	std::cout << "Memory adress of the pointer stringPTR: " << &stringPTR << std::endl;
	std::cout << "Memory adress of the reference stringREF: " << &stringREF << std::endl;
	std::cout << "VALUES" << std::endl;
	std::cout << "Value of the string variable: " << str << std::endl;
	std::cout << "Value of the pointer stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of the reference stringREF: " << stringREF << std::endl;
	return (0);
}
