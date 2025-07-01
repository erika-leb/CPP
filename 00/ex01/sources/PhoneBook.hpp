#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
#include <curses.h>
# include <iomanip>
# include <stdlib.h>
# include "Contact.hpp"

class PhoneBook {

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void		addContact(void);
		void		searchContact(void);

	private:
		int		getElement(std::string s, std::string str);
		bool		isOnlySpace(std::string str);
		void		printContactLine(void);
		std::string trunc(std::string str);
		bool		isNum(std::string str);
		Contact 	_arr[8];
		int			_index;
};

#endif
