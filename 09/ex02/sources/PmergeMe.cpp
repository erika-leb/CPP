#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(char **av)
{
    long n;
    std::vector<int> lst;
    // std::string d;
    int i = 1;
    while (av[i])
    {
        int j = 0;
        while (av[i][j])
        {
            if (!(av[i][j] >= '0' && av[i][j] <= '9'))
                throw std::invalid_argument("invalid argument");
            // d = av[i];
            j++;
        }
        n = std::strtol(av[i], NULL, 10);
        if (n > INT_MAX)
            throw std::invalid_argument("invalid argument");
        lst.push_back(n);
        i++;
    }
    _vect = lst;
    _deq.assign(lst.begin(), lst.end());
    _pairSize = 1;
}

PmergeMe::PmergeMe(const PmergeMe &src) : _vect(src._vect), _deq(src._deq)
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        _vect = src._vect;
        _deq = src._deq;
    }
    return (*this);
}

void PmergeMe::sort()
{
    //     algoSort(_vect);
    //     algoSort(_deq);
    pairing(_vect); //faudra faire pareil avec l'autre liste
    pairing(_deq);
    // moveBloc(_deq, 1, 1, 0);
    // moveBloc(_deq, 4, 5, 0);
}

void PmergeMe::print(int n) const
{
    if (n == 1)
    {
        std::cout << "Before:" << std::endl;
        std::cout << "vector: ";
        for (std::vector<int>::const_iterator it = _vect.begin(); it != _vect.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "deque: ";
        for (std::deque<int>::const_iterator it = _deq.begin(); it != _deq.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
    }
    if (n == 2)
    {
        std::cout << "After:" << std::endl;
        std::cout << "vector: ";
        for (std::vector<int>::const_iterator it = _vect.begin(); it != _vect.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "deque: ";
        for (std::deque<int>::const_iterator it = _deq.begin(); it != _deq.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
    }
    if (n == 3)
    {
        std::cout << "debeug:" << std::endl;
        // std::cout << "vector: ";
        // for (std::vector   <int>::const_iterator it = _vect.begin(); it != _vect.end(); ++it)
        //     std::cout << *it << " ";
        // std::cout << std::endl;
        std::cout << "deque: ";
        for (std::deque<int>::const_iterator it = _deq.begin(); it != _deq.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
    }
    else
        return;
}
