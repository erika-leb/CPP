#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	// this->_arr;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

std::string PhoneBook::trunc(std::string s1)
{
	int	s;
	int i;
	std::string	s2;

	s = s1.size();
	if (s > 10)
	{
		i = 0;
		while (i < 9)
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '.';
	}
	else
		s2 = s1;
	return (s2);
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
	while (i < 7 && _arr[i].getFirstName() != "")
	{
		std::cout << "|" << std::setw(10) << i + 1 << "|"
					<< std::setw(10) << trunc(_arr[i].getFirstName()) << "|"
					<< std::setw(10) << trunc(_arr[i].getLastName()) << "|"
					<< std::setw(10) << trunc(_arr[i].getNickName()) << "|" << std::endl;
		i++;
	}
	return ;
}

void		PhoneBook::setElement(std::string s)
{
	std::string	str;

	while (str == "") //verifier si eof ??
	{
		if (s == "fn")
			std::cout << "Contact first name ?" << std::endl;
		if (s == "ln")
			std::cout << "Contact last name ?" << std::endl;
		if (s == "nn")
			std::cout << "Contact nickname ?" << std::endl;
		if (s == "pn")
			std::cout << "Contact phone number?" << std::endl;
		if (s == "ds")
			std::cout << "Contact darkest secret ?" << std::endl;
		std::getline(std::cin, str);
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
	}
	return ;
}


void	PhoneBook::addContact()
{
	setElement("fn");
	setElement("ln");
	setElement("nn");
	setElement("pn");
	setElement("ds");
	(this->_index)++;
	return ;
}

// void	PhoneBook::addContact()
// {
// 	std::string	s;
// 	Contact		contact;

// 	while (s == "")
// 	{
// 		std::cout << "Contact fist name ?" << std::endl;
// 		std::cin >> s;
// 	}
// 	this->_arr[_index].setFirstName(s); //pk ca marche pas
// 	s = "";
// 	while (s == "")
// 	{
// 		std::cout << "Contact last name ?" << std::endl;
// 		std::cin >> s;
// 	}
// 	this->_arr[this->_index].setLastName(s);
// 	// contact.setLastName(s);
// 	s = "";
// 	while (s == "")
// 	{
// 		std::cout << "Contact nickname ?" << std::endl;
// 		std::cin >> s;
// 	}
// 	this->_arr[this->_index].setNickName(s);
// 	// contact.setNickName(s);
// 	s = "";
// 	while (s == "") // verifier ici que c'est un numero de tel
// 	{
// 		std::cout << "Contact phone number ?" << std::endl;
// 		std::cin >> s;
// 	}
// 	this->_arr[this->_index].setPhoneNumber(s);
// 	// contact.setPhoneNumber(s);
// 	s = "";
// 		while (s == "")
// 	{
// 		std::cout << "Contact darkest secret ?" << std::endl;
// 		std::cin >> s;
// 	}
// 	this->_arr[this->_index].setDarkSecret(s);
// 	// contact.setDarkSecret(s);
// 	//this->arr[0] = contact;

// 	return ;
// }
