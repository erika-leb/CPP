#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cerr << "Error : enter argument" << std::endl;
        return (1);
    }
    try 
    {
        PmergeMe seq(av);
        seq.print(1);
        seq.sort();
        seq.print(2);
    }
    catch(std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return (0);
}