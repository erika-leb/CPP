#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(char **av)
{
    long n;
    std::vector< std::pair<int, int> > lst;
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
        lst.push_back(std::make_pair(static_cast<int>(n), -1));
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
    mergeInsert(_vect);
    pairing(_deq);
    mergeInsert(_deq);
    // moveBloc(_deq, 1, 1, 0);
    // moveBloc(_deq, 4, 5, 0);
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

// int PmergeMe::getJacobNb(int n)
// {
//     if (n == 0)
//         return jacobNb(3);
//     else
//         return    
// }


// void PmergeMe::insertPend(std::vector<int> &lst, std::vector<int> &pend)
// {
//     size_t i = 0;
//     size_t k = 1;
//     std::vector<std::pair<int, int> > pendBis;
//     for(std::vector<int>::iterator it = pend.begin(); it != pend.end(); ++it)
//     {
//         if (k * _pairSize - 1 == i)
//         {
//             pendBis.push_back(std::make_pair(*it, k + 1));            
//             k++;
//         }
//         else
//             pendBis.push_back(std::make_pair(*it, -1));
//         i++;
//     }
//     k = 1;
//     i = 0;
//     std::vector<std::pair<int, int> > mainBis;
//     for(std::vector<int>::iterator it = lst.begin(); it != lst.end(); ++it)
//     {
//         // std::cout << "_pairSize = " << _pairSize << "; k * _pairSize - 1 =" << k * _pairSize - 1 << "; i = " << i << std::endl;
//         if (k * _pairSize - 1 == i)
//         {
//             mainBis.push_back(std::make_pair(*it, k - 1));            
//             k++;
//         }
//         else
//             mainBis.push_back(std::make_pair(*it, -1));
//         i++;
//     }
//     printPair(pendBis);
//     printPair(mainBis);
// }

// void PmergeMe::insertPend(std::deque<int> &lst, std::deque<int> &pend)
// {
//     (void)lst;
//     (void) pend;
// }


void PmergeMe::print(int n) const
{
    if (n == 1)
    {
        std::cout << "Before:" << std::endl;
        std::cout << "vector: ";
        for (std::vector< std::pair<int, int> >::const_iterator it = _vect.begin(); it != _vect.end(); ++it)
            std::cout << it->first << " ";
        std::cout << std::endl;
        std::cout << "deque: ";
        for (std::deque< std::pair<int, int> >::const_iterator it = _deq.begin(); it != _deq.end(); ++it)
            std::cout << it->first << " ";
        std::cout << std::endl;
    }
    if (n == 2)
    {
        std::cout << "After:" << std::endl;
        std::cout << "vector: ";
        for (std::vector<std::pair<int, int> >::const_iterator it = _vect.begin(); it != _vect.end(); ++it)
            std::cout << it->first << " ";
        std::cout << std::endl;
        std::cout << "deque: ";
        for (std::deque<std::pair<int, int> >::const_iterator it = _deq.begin(); it != _deq.end(); ++it)
            std::cout << it->first << " ";
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
        for (std::deque< std::pair<int, int> >::const_iterator it = _deq.begin(); it != _deq.end(); ++it)
            std::cout << it->first << " ";
        std::cout << std::endl;
    }
    else
        return;
}
