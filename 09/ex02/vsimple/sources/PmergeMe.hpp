#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <climits>
# include <cstdlib>
# include <vector>
# include <deque>
# include <algorithm>

class PmergeMe {
    public:
        PmergeMe(char **av);
        PmergeMe(const PmergeMe &src);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &src);

        void sort();

        template <typename T>
        void moveBloc(T &lst, size_t begin, size_t end, size_t pos)
        {
            // std::cerr << " begin = " << begin << "; end = " << end << "; pos = " << pos << std::endl;
            // print(3);
            if (pos >= lst.size() || begin >= lst.size() || end >= lst.size() || begin > end)
            {
                std::cerr << "probleme attention" << std::endl; // a enlever plus tard
                return ;
            }
            
            typename T::iterator itbegin = lst.begin();
            typename T::iterator itend = lst.begin();
            
            std::advance(itbegin, begin);
            std::advance(itend, end + 1);

            std::vector<int> tmp(itbegin, itend);
            lst.erase(itbegin, itend); //ici aussi
            typename T::iterator itpos = lst.begin();
            if (pos >= lst.size())
            {
                pos = pos - (end - begin + 1); // pas sur non plus
            }
            std::advance(itpos, pos);
            lst.insert(itpos, tmp.begin(), tmp.end());
        }

        template <typename T>
        T createPend(T &lst)
        {
            T pend;

            int k = 3;
            std::cerr << "avant modif" << std::endl;
            printCont(pend);
            printCont(lst);
            while ((k * _pairSize) - 1 < lst.size())// tant qu il existe un b
            {
                typename T::iterator itbegin = lst.begin();
                typename T::iterator itend = lst.begin();

                std::advance(itbegin, (k - 1) * _pairSize); // pas sur
                std::advance(itend, k * _pairSize); // pas sur
                
                pend.insert(pend.end(), itbegin, itend);
                lst.erase(itbegin, itend);
                
                // std::cerr << k << "eme tour; apres modif" << std::endl;
                // printCont(pend);
                // printCont(lst);
                // std::cerr << "fin" << std::endl;
                k++;
            }
            std::cerr << "apres modif" << std::endl;
            printCont(pend);
            printCont(lst);
            std::cerr << "fin" << std::endl;
            return (pend);
        }

        template <typename T>
        void mergeInsert(T &lst)
        {
            int f = 0;
            // std::cout << "j0  = " << jacobNb(0) << std::endl;
            _pairSize /= 2; //pour le premier on est a 8
            while (_pairSize >= 1)
            {
                // std::cout << "r = " << _pairSize << " size = " <<lst.size() << std::endl;
                if (f == 0 && _pairSize * 3 > lst.size()) // revoir caaa
                {
                    std::cout << "r = " << _pairSize << " et on a passe" << std::endl;
                    _pairSize /= 2; //pour le premier on est a 8
                    // f = 1;
                    continue;
                }
                // std::cout << "verif r = " << _pairSize << std::endl;
                T pend = createPend(lst);
                insertPend(lst, pend);
                _pairSize /= 2; //pour le premier on est a 8
                // f = 1;
            }
            _pairSize = 1;
        }

        template <typename T>
        void pairing(T &lst)
        {
            _pairSize = 1; //attention ici !!!!!!! faut trouver une solution
            while (_pairSize * 2 <= lst.size())
            {
                // std::cout << "r = " << _pairSize << std::endl;
                size_t k = 1;
                while (((k + 1) * _pairSize) - 1 < lst.size()) // ici on verifie que les deux paires a comparer existent
                {
                    if (lst[k * _pairSize - 1] > lst[(k + 1) * _pairSize - 1])
                    {
                        moveBloc(lst, k * _pairSize, (k + 1) * _pairSize - 1, (k - 1) * _pairSize);
                    }    
                    k += 2; //doute
                }
                _pairSize *= 2; // on passe a la pair de paire suivante
            }
        }

        template <typename T>
        void printCont(T &lst) const
        {
            std::cout << "container:" << std::endl;
            for (typename T::const_iterator it = lst.begin(); it != lst.end(); ++it)
                std::cout << *it << " ";
            std::cout << std::endl;
        }


        template <typename T> 
        void printPair(const T &lst) // surement a supprimer a la fin
        {
            std::cout << "container de pair:" << std::endl;
            for (typename T::const_iterator it = lst.begin(); it != lst.end(); ++it)
            {
                std::cout << "(" << it->first << "," << it->second << ") ";
            }
            std::cout << std::endl;
        }

        void insertPend(std::vector<int> &lst, std::vector<int> &pend);
        void insertPend(std::deque<int> &lst, std::deque<int> &pend);

        int jacobNb(int n);

        void print(int n) const;

    private:
        std::vector<int> _vect;
        std::deque <int> _deq;
        size_t _pairSize;

        PmergeMe();

} ;

#endif