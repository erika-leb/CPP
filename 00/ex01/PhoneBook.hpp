#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook {

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	addContact(void);
		void	searchContact(void);

	private:
		void	setElement(std::string s);
		// void	printLine(int i, int f);
		std::string trunc(std::string str);
		Contact _arr[8];
		int		_index;
};

#endif
