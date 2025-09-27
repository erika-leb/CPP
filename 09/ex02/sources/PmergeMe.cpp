#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}
PmergeMe::PmergeMe(char **av)
{
    long n;
    std::vector< std::pair<int, std::pair<char, int> > > lst;
    int i = 1;
    while (av[i])
    {
        int j = 0;
        while (av[i][j])
        {
            if (!(av[i][j] >= '0' && av[i][j] <= '9'))
                throw std::invalid_argument("invalid argument");
            j++;
        }
        n = std::strtol(av[i], NULL, 10);
        if (n > INT_MAX)
            throw std::invalid_argument("invalid argument");
        lst.push_back(std::make_pair(static_cast<int>(n), std::make_pair('x', -1)));
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

void PmergeMe::sort(int n)
{
	if (n == 1)
	{
    	pairing(_vect);
    	mergeInsert(_vect);
	}
    else
	{
		pairing(_deq);
    	mergeInsert(_deq);
	}

}

int PmergeMe::jacobNb(int n)
{
    if (n == 0)
        return (0);
    else if (n == 1)
        return (1);
    else
        return (jacobNb(n - 1) + 2 * jacobNb(n - 2));
}

void PmergeMe::print(int n) const
{
    if (n == 1)
    {
        std::cout << "Before:  " ;
        for (std::vector< std::pair<int, std::pair<char, int> > >::const_iterator it = _vect.begin(); it != _vect.end(); ++it)
            std::cout << it->first << " ";
        std::cout << std::endl;
        // std::cout << "deque: ";
        // for (std::deque< std::pair<int, std::pair<char, int> > >::const_iterator it = _deq.begin(); it != _deq.end(); ++it)
        //     std::cout << it->first << " ";
        // std::cout << std::endl;
    }
    if (n == 2)
    {
        std::cout << "After:  " ;
        for (std::vector<std::pair<int, std::pair<char, int> > >::const_iterator it = _vect.begin(); it != _vect.end(); ++it)
            std::cout << it->first << " ";
        std::cout << std::endl;
        // std::cout << "deque: ";
        // for (std::deque<std::pair<int, std::pair<char, int> > >::const_iterator it = _deq.begin(); it != _deq.end(); ++it)
        //     std::cout << it->first << " ";
        // std::cout << std::endl;
    }
    else
        return;
}
