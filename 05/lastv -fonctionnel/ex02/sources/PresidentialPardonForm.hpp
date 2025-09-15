#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

		std::string getTarget() const;
		void execute(Bureaucrat const &executor) const;

	private:
		std::string _target;

};

#endif
