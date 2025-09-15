#include "Form.hpp"

int main()
{
    try {
		std::cout << "---------creation of Bureaucrats------------" <<std::endl;
        Bureaucrat a("Jack", 1);
        Bureaucrat b("Esther", 150);
		std::cout << "---------creation of Forms-----------------" <<std::endl;
        Form topSecret("TopSecret", 1, 1);
        Form trash("Usual", 150, 150);
		std::cout << "---------Overload tests--------------------" <<std::endl;
        std::cout << a << b << std::endl;
        std::cout << topSecret << trash << std::endl;

		std::cout << "---------Jack signs topSecret form--------------------" <<std::endl;
        a.signForm(topSecret);
		std::cout << "---------Jack signs topSecret form--------------------" <<std::endl;
        b.signForm(trash);
		// std::cout << "---------Esther tries to sign topSecret form--------------------" <<std::endl;
        // b.signForm(topSecret);
        std::cout << topSecret << trash;
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}
