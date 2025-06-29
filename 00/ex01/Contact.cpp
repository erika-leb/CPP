#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::setFirstName(std::string str)
{
	if (str != "")
		this->_FirstName = str;
	return ;
}

std::string	Contact::getFirstName(void) const
{
	return (this->_FirstName);
}

void	Contact::setLastName(std::string str)
{
	if (str != "")
		this->_LastName = str;
	return ;
}

std::string	Contact::getLastName(void) const
{
	return (this->_LastName);
}

void	Contact::setNickName(std::string str)
{
	if (str != "")
		this->_NickName = str;
	return ;
}

std::string	Contact::getNickName(void) const
{
	return (this->_NickName);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (this->_PhoneNumber);
}

void	Contact::setPhoneNumber(std::string str)
{
	if (str != "")
		this->_PhoneNumber = str;
	return ;
}

std::string	Contact::getDarkSecret(void) const
{
	return (this->_DarkSecret);
}

void	Contact::setDarkSecret(std::string str)
{
	if (str != "")
		this->_DarkSecret = str;
	return ;
}
