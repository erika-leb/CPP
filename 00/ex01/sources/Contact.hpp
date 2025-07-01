#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {

	public:
		Contact(void);
		~Contact(void);

		void		setFirstName(std::string);
		std::string	getFirstName(void) const;
		void		setLastName(std::string);
		std::string	getLastName(void) const;
		void		setNickName(std::string);
		std::string	getNickName(void) const;
		void		setPhoneNumber(std::string);
		std::string	getPhoneNumber(void) const;
		void		setDarkSecret(std::string);
		std::string	getDarkSecret(void) const;

	private:
		std::string	_FirstName;
		std::string	_LastName;
		std::string	_NickName;
		std::string	_PhoneNumber;
		std::string _DarkSecret;
};

#endif
