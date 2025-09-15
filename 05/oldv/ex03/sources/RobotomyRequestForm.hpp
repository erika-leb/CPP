#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

		std::string getTarget() const; //doute ici

		void execute(Bureaucrat const & executor) const ;

	private:
		std::string _target;
};

#endif
