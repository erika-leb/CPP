#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

std::string PhoneBook::trunc(std::string s1)
{
	if (s1.size() > 10)
		return (s1.substr(0, 9) + '.');
	else
		return (s1);
}

void	PhoneBook::printContactLine(void)
{
	int	index;
	std::string s;

	std::cout << "Contact index ?" << std::endl;
	while (true)
	{
		if (!std::getline(std::cin, s))
		{
			std::cout << "EOF detected. " << std::endl;
			return;
		}
		if (s.size() == 1 && s[0] >= '1' && s[0] <= '8')
			break ;
		std::cout << "Invalid index. Contact index ?" << std::endl;
	}
	// std::getline(std::cin, s);
	// while (s.size() != 1 || s[0] < '1' || s[0] > '8')
	// {
	// 	std::cout << "Invalid index. Contact index ?" << std::endl;
	// 	std::getline(std::cin, s);
	// }
	index = s[0] - '1';
	if (_arr[index].getFirstName() == "")
	{
		std::cout << "No contact at this index" << std::endl;
		return ;
	}
	std::cout << "Contact First Name : " << _arr[index].getFirstName() << std::endl
				<< "Contact Last Name : " << _arr[index].getLastName() << std::endl
				<< "Contact NickName : " << _arr[index].getNickName() << std::endl
				<< "Contact Phone Number :" << _arr[index].getPhoneNumber() << std::endl
				<< "Contact Darkest Secret : " << _arr[index].getDarkSecret() << std::endl;
	return ;
}

void	PhoneBook::searchContact(void)
{
	int			i;

	i = 0;
	if (_arr[0].getFirstName() == "")
	{
		std::cout << "Empty Phonebook" << std::endl;
		return ;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	while (i < 8 && _arr[i].getFirstName() != "")
	{
		std::cout << "|" << std::setw(10) << i + 1 << "|"
					<< std::setw(10) << trunc(_arr[i].getFirstName()) << "|"
					<< std::setw(10) << trunc(_arr[i].getLastName()) << "|"
					<< std::setw(10) << trunc(_arr[i].getNickName()) << "|" << std::endl;
		i++;
	}
	printContactLine();
	return ;
}

bool		PhoneBook::isNum(std::string str)
{
	int	i;

	i = 1;
	if (!((str[0] >= '0' && str[0] <= '9') || str[0] == '+'))
		return (false);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

bool PhoneBook::isOnlySpace(std::string str)
{
	int	i;
	int f;

	i = 0;
	f = 0;
	while (str[i])
	{
		if (!(std::isspace(str[i])))
			f = 1;
		if (str[i] >= 9 && str[i] <= 13)
			f = 2;
		i++;
	}
	if (f == 0 || f == 2)
		return (true);
	else
		return (false);
}

int		PhoneBook::getElement(std::string s, std::string s1)
{
	std::string	str;

	std::cout << s1 << std::endl;
	while (1)
	{
		if (!std::getline(std::cin, str))
		{
			std::cout << "la." << std::endl;
			str.clear();
			return (1);
		}
		if (str.empty() || isOnlySpace(str) == true || str.find('\033') != std::string::npos || (s == "pn" && isNum(str) == false))
			std::cout << "Input not accepted.Try again." << std::endl;
		else
		{
			if (s == "fn")
				this->_arr[_index % 8].setFirstName(str);
			if (s == "ln")
				this->_arr[_index % 8].setLastName(str);
			if (s == "nn")
				this->_arr[_index % 8].setNickName(str);
			if (s == "pn")
				this->_arr[_index % 8].setPhoneNumber(str);
			if (s == "ds")
				this->_arr[_index % 8].setDarkSecret(str);
			return (0);
		}
	}
	std::cout << "ici." << std::endl;
	str.clear();
	return (1);

	// std::cout << s1 << std::endl;
	// std::getline(std::cin, str);
	// if (std::cin.eof())
	// 	return;
	// while (str.empty() || isOnlySpace(str) == true || str.find('\033') != std::string::npos || (s == "pn" && isNum(str) == false))
	// {
	// 	std::cout << "Input not accepted.Try again." << std::endl;
	// 	std::getline(std::cin, str);
	// 	if (std::cin.eof())
	// 		return;
	// }
	// if (s == "fn")
	// 	this->_arr[_index % 8].setFirstName(str);
	// if (s == "ln")
	// 	this->_arr[_index % 8].setLastName(str);
	// if (s == "nn")
	// 	this->_arr[_index % 8].setNickName(str);
	// if (s == "pn")
	// 	this->_arr[_index % 8].setPhoneNumber(str);
	// if (s == "ds")
	// 	this->_arr[_index % 8].setDarkSecret(str);
	// return ;
}

void	PhoneBook::addContact()
{
	if (getElement("fn", "Contact first name ?") == 1)
		return ;
	if (getElement("ln", "Contact last name ?") == 1)
		return ;
	if (getElement("nn", "Contact nickname ?") == 1)
		return ;
	if (getElement("pn", "Contact phone number?") == 1)
		return ;
	if (getElement("ds", "Contact darkest secret ?") == 1)
		return ;
	(this->_index)++;
	return ;
}
