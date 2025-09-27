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
		clock_t startVect = clock();
		seq.sort(1);
		clock_t endVect = clock();
		clock_t startDeq = clock();
		seq.sort(2);
		clock_t endDeq = clock();
		seq.print(2);
		double durationVec = static_cast<double>(endVect - startVect) / CLOCKS_PER_SEC * 1e6;
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector :" << durationVec << " µs" << std::endl;
		double durationDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque :" << durationDeq << " µs" << std::endl;
	}
    catch(std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return (0);
}
