#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
	std::string str;
	PhoneBook	ph;

	while (1)
	{
		std::cout << "Enter a command :" << std::endl;
		std::getline(std::cin, str);
		if (str == "EXIT")
			return (0);
		else if (std::cin.eof())
			break ;
		else if (str == "ADD")
			ph.addContact();
		else if (str == "SEARCH")
			ph.searchContact();
		else
			std::cout << "Authorized commands : ADD, SEARCH and EXIT" << std::endl;
	}
	//ya t il vraiment besoin de clear str ?/
	return (0);
}
