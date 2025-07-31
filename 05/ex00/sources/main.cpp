#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat *b = NULL;

    try {
        std::cout << "=========Bureaucrat construction=========" << std::endl;
        Bureaucrat a("Johnny", 150);
        std::cout << "=========Bureaucrat pointer construction=========" << std::endl;
        b = new Bureaucrat("Brad", 1);
        std::cout << "=========Incrementation test=========" << std::endl;
        std::cout << "b name: " << b->getName() << "; grade: " << b->getGrade() << std::endl;
        a.incrementGrade(2);
        std::cout << a << std::endl;
        std::cout << "=========decrementation test=========" << std::endl;
        b->incrementGrade(1);
        std::cout << *b << std::endl;
        delete b;
    }
    catch (std::exception &e){
        if (b != NULL)
            delete b;
    std::cerr << "Exception catched : " << e.what() << std::endl;
    }
    return (0);
}