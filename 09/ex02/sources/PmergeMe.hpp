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

        // template <typename T>
        // void algoSort(T &lst)
        // {

        // }

        // template <typename T>
        // void moveBloc(typename T::iterator begin, typename T::iterator end, typename T::iterator pos) // (debut du bloc, fin du bloc, nouveau positionnement )    
        // {
        //     std::T<int> tmp;
        //     for (T::iterator it = begin; it != end; ++it)
        //         tmp.push(*it);
        // }

        // template <typename T>
        // void moveBloc(T &lst, size_t begin, size_t end, size_t pos)
        // {
        //     if (pos >= lst.size() || begin >= lst.size() || end >= lst.size() || begin > end)
        //     {
        //         std::cerr << "probleme attention" << std::endl; // a enlever plus tard
        //         return ;
        //     }
        //     T tmp(lst.begin() + begin, lst.begin() + end + 1); // pas sure ici
        //     lst.erase(lst.begin() + begin, lst.begin() + end + 1); //ici aussi
        //     // {
        //     //     std::cerr << "pour debug" << std::endl;
        //     //     print(1);
        //     //     std::cerr << "fin debug" << std::endl;
        //     // }
        //     if (pos >= lst.size())
        //     {
        //         pos = pos - (end - begin + 1); // pas sur non plus
        //         std::cerr << "ici" << std::endl;
        //     }
        //     lst.insert(lst.begin() + pos, tmp.begin(), tmp.end());
        //     // erase
        //     // insert 
        // }

        template <typename T>
        void moveBloc(T &lst, size_t begin, size_t end, size_t pos)
        {
            std::cerr << " begin = " << begin << "; end = " << end << "; pos = " << pos << std::endl;
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

            // T tmp(lst.begin() + begin, lst.begin() + end + 1); // pas sure ici
            std::vector<int> tmp(itbegin, itend);
            // lst.erase(lst.begin() + begin, lst.begin() + end + 1); //ici aussi
            lst.erase(itbegin, itend); //ici aussi
            {
                // std::cerr << "pour debug" << std::endl;
                // print(3);
                // std::cerr << "fin debug" << std::endl;
                // std::cerr << "top = " <<tmp[0] << std::endl;
            }
            typename T::iterator itpos = lst.begin();
            if (pos >= lst.size())
            {
                pos = pos - (end - begin + 1); // pas sur non plus
                
                // std::cerr << "ici" << std::endl;
            }
            std::advance(itpos, pos);
            // std::cerr << "pos = " << pos << std::endl;
            // lst.insert(lst.begin() + pos, tmp.begin(), tmp.end());
            print(3);
            std::cerr << "tmp.begin =" << *tmp.begin() << std::endl;
            lst.insert(itpos, tmp.begin(), tmp.end());
            print(3);
            // erase
            // insert 
        }
// template <typename T>
// void moveBloc(T &lst, size_t begin, size_t end, size_t pos)
// {
//     // vérifications d'indices
//     if (lst.empty() || begin > end || end >= lst.size())
//         return;

//     size_t len = end - begin + 1;

//     // itérateurs sur la plage [begin, end] (itend = one-past)
//     typename T::iterator itbegin = lst.begin();
//     std::advance(itbegin, begin);
//     typename T::iterator itend = itbegin;
//     std::advance(itend, len);

//     // copie dans un tampon du type exact des éléments
//     std::vector<typename T::value_type> tmp;
//     tmp.reserve(len);
//     tmp.insert(tmp.end(), itbegin, itend);

//     // suppression du bloc dans le conteneur (invalide itérateurs obtenus avant)
//     lst.erase(itbegin, itend);

//     // calcul de la nouvelle position d'insertion après la suppression
//     size_t new_pos;
//     if (pos > end) {
//         // la position d'origine était après le bloc retiré : on décale
//         new_pos = pos - len;
//     } else if (pos < begin) {
//         // insertion avant le bloc retiré : position inchangée
//         new_pos = pos;
//     } else {
//         // pos dans le bloc supprimé : choix arbitraire cohérent -> insérer à 'begin'
//         new_pos = begin;
//     }

//     if (new_pos > lst.size()) new_pos = lst.size();

//     // obtenir un itérateur valide pour l'insertion
//     typename T::iterator itpos = lst.begin();
//     std::advance(itpos, new_pos);

//     // insertion du bloc copié
//     lst.insert(itpos, tmp.begin(), tmp.end());
// }


        // template <typename T>
        // void pairing(T &lst)
        // {
        //     while (_pairSize * 2 <= lst.size())
        //     {
        //         size_t k = 1;
        //         while (((k + 1) * _pairSize) - 1 < lst.size()) // ici on verifie que les deux paires a comparer existent
        //         {
        //             if (*(lst.begin() + k * _pairSize - 1) > *(lst.begin() + (k + 1) * _pairSize - 1))
        //                 moveBloc(lst, k * _pairSize, (k + 1) * _pairSize - 1, (k - 1) * _pairSize);
        //             k += 2; //doute
        //         }
        //         _pairSize *= 2; // on passe a la pair de paire suivante
        //     }
        // }

        template <typename T>
        void pairing(T &lst)
        {
            _pairSize = 1; //attention ici !!!!!!! faut trouver une solution
            // std::cerr << "et la ?" << std::endl;
            while (_pairSize * 2 <= lst.size())
            {
                size_t k = 1;
                // std::cerr << "et ici ?" << std::endl;
                while (((k + 1) * _pairSize) - 1 < lst.size()) // ici on verifie que les deux paires a comparer existent
                {
                    // std::cerr << "passe t on ici ?" << std::endl;
                    // std::cerr << "lst[k * _pairSize - 1 : " << lst[k * _pairSize - 1] << std::endl;
                    // std::cerr << "lst[(k + 1) * _pairSize - 1] : " << lst[(k + 1) * _pairSize - 1] << std::endl;
                    
                    if (lst[k * _pairSize - 1] > lst[(k + 1) * _pairSize - 1])
                    {
                        // std::cerr << "ou ici ?" << std::endl;
                        // std::cerr << "moveBloc(lst, " << k * _pairSize << ", " << (k + 1) * _pairSize - 1 << ", " << (k - 1) * _pairSize << ");" << std::endl;
                        moveBloc(lst, k * _pairSize, (k + 1) * _pairSize - 1, (k - 1) * _pairSize);
                    }    
                    k += 2; //doute
                }
                // std::cerr << "debut debug" << std::endl;
                // print(1);
                // std::cerr << "fin debug" << std::endl;
                _pairSize *= 2; // on passe a la pair de paire suivante
            }
        }

        void print(int n) const;

    private:
        std::vector<int> _vect;
        std::deque<int> _deq;
        size_t _pairSize;

        PmergeMe();

} ;

#endif