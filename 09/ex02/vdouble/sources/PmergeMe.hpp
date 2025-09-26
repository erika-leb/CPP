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
            if (pos >= lst.size() || begin >= lst.size() || end >= lst.size() || begin > end)
            {
                std::cerr << "probleme attention" << std::endl; // a enlever plus tard
                return ;
            }

            typename T::iterator itbegin = lst.begin();
            typename T::iterator itend = lst.begin();

            std::advance(itbegin, begin);
            std::advance(itend, end + 1);

            std::vector< std::pair<int, std::pair<char, int> > > tmp(itbegin, itend);
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
        T createPend(T &lst, T&remain)
        {
            T pend;
            int k = 3;
            size_t i = 0;
            size_t j = 1;
			// int l;

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

                k++;
            }
			k = 1;
			while (k * _pairSize - 1 < lst.size())
				k++;
			k--;
			if (k * _pairSize < lst.size())
			{
				remain.insert(remain.begin(), lst.begin() + k * _pairSize, lst.end());
				lst.erase(lst.begin() + k * _pairSize, lst.end());
			}

			// if (lst.begin() + l != lst.end())
			// {
			// 	std::cout << "l = " << l << std::endl;
			// 	std::cout << "I " << std::endl;

			// 	std::cout << "don't" << std::endl;
			// }
			// std::cout << "(k * _pairSize) - 1 = " << (k * _pairSize) - 1 << std::endl;
			// std::cout << "((k - 1) * _pairSize) - 1 = " << ((k - 1) * _pairSize) - 1 << std::endl;
			// std::cout << "man" << std::endl;
			// l = (k - 1) * _pairSize - 1;
			// if (lst.begin() + l != lst.end())
			// {
			// 	std::cout << "l = " << l << std::endl;
			// 	remain.insert(remain.begin(), lst.begin() + l, lst.end());
			// 	std::cout << "I " << std::endl;
			// 	lst.erase(lst.begin() + l, lst.end());
			// 	std::cout << "don't" << std::endl;
			// }
			// while (l < lst.size())
			// {
			// 	remain.insert(remain.end(), lst.begin() + l, )
			// 	l++;
			// }
            for(typename T::iterator it = pend.begin(); it != pend.end(); ++it)
            {
                if (j * _pairSize - 1 == i)
                {
					it->second.first = 'b';
                    it->second.second = j + 1;
                    j++;
                }
                else
				{
					it->second.first = 'b';
                    it->second.second = -1;
				}
                i++;
            }
            j = 1;
            i = 0;
            for(typename T::iterator it = lst.begin(); it != lst.end(); ++it)
            {
                if (j * _pairSize - 1 == i)
                {
					it->second.first = 'a';
                    it->second.second= j - 1;
                    j++;
                }
                else
				{
					it->second.first = 'b';
                    it->second.second = -1;

				}
                i++;
            }

            std::cerr << "apres modif create pend (pend et lst)" << std::endl;
            printCont(pend);
            printCont(lst);
			printCont(remain);
            std::cerr << "fin" << std::endl;
            return (pend);
        }

        template <typename T>
        int getLastInd(T &pend)
        {
            int res;
            for (typename T::iterator it = pend.begin(); it != pend.end(); ++it) //ne sert a rien en soit
                res = it->second.second;
            return res; // a verifier
        }

        template <typename T>
        T createBloc(int value, T &pend)
        {
            T tmp;
            typename T::iterator it = pend.begin();

            // std::cerr << "all night, print pend = ";
            // printPair(pend);
            while (it->second.second != value)
                ++it;
            // std::cout << "haha  it first = " << it->first << "; second.second = " << it->second.second << std::endl;
            if (it == pend.end()) //inutile normalement
                return tmp;
            while (it != pend.begin())
            {
                // std::cerr << "dishes" << std::endl;
                // std::cout << "it first = " << it->first << "; second.second = " << it->second.second << std::endl;
                if (it->second.second != (-1))
                {
                    // std::cout << "r = " << _pairSize << "; first = "<< it->first <<"; it second.second = "<< it->second.second << std::endl;
                    tmp.insert(tmp.end(), it - _pairSize + 1, it + 1);
                }
                it--;
                // std::cout << "first = "<< it->first <<"; it second.second = "<< it->second.second << std::endl;
            }
            if (it == pend.begin() && _pairSize == 1)
                tmp.insert(tmp.end(), it - _pairSize + 1, it + 1);
            // while (it != pend.end() && it->second.second <= value)
            // {
            //     tmp.insert(tmp.begin(), *it);
            //     // tmp.push_back(*it);
            //     ++it;
            // }

            // std::cerr << "bloc reduit et a l'ENVERS = ";
            // printPair(tmp);
            // printPair(pend);
            return (tmp);
        }

		template <typename T>
		void changeValue(typename T::iterator tmpitbegin, typename T::iterator tmpitend)
		{
			for (typename T::iterator it = tmpitbegin; it != tmpitend; it++)
				it->second.second = -1;
		}

        template <typename T>
        void insertBloc(T &lst, T &tmp) // il faut comparer tmp et lst, a la fin, les elements de tmp doivent avoir ete insere dans lst
        {
            std::cerr << "AVANT = " << std::endl;
            printPair(tmp);
            printPair(lst);
			// std::cerr << "r = " << _pairSize << std::endl;
            for (typename T::iterator tmpIt = tmp.begin(); tmpIt != tmp.end(); ++tmpIt)
            {
                if (tmpIt->second.second != -1)
                {
					// std::cout << "paul" << std::endl;
                    // for (typename T::iterator ite = lst.begin(); ite != lst.end(); ++ite)
                    for (typename T::iterator lstIt = lst.begin(); lstIt != lst.end() && !(lstIt->second.first == 'a' && lstIt->second.second == tmpIt->second.second + 2); ++lstIt)
                    {
                        // k = 1;
                        std::cout << "kim et lstIT second.second ="  << lstIt->second.second<< std::endl;
                        if (lstIt->second.second != -1)
                        {
                            std::cout <<"yas et tmpIT =" << tmpIt->first << "; lstIT first = " << lstIt->first<< std::endl;
                            if ((lstIt + 1) == lst.end() && tmpIt->first > lstIt->first)//si on est au dernier element de lst
							{
								typename T::iterator tmpitbegin =  tmpIt - (_pairSize - 1);
                                typename T::iterator tmpitend = tmpIt + 1;
                                typename T::iterator lstitpos;
                                // if (lstIt != lst.begin() && _pairSize != 1)
                                //     lstitpos = lstIt - 1;
                                // else
                                lstitpos = lst.end();
                                // typename T::iterator lstitpos = lst.begin();
                                // std::advance(tmpitbegin, (k - 1) * _pairSize);
                                // std::advance(tmpitend, k * _pairSize);
                                // std::advance(lstitpos, i * _pairSize);
								std::cout << "adri" << std::endl;
                                std::cout << "el ; valeur de lst ou on va se positionner = " << lstitpos->first << std::endl;
                                std::cout <<"el ;valeur de debut de tmp a indroduire = " << tmpitbegin->first << std::endl;
                                // changeValue<T>(tmpitbegin, tmpitend);
								lst.insert(lstitpos, tmpitbegin, tmpitend);
                                // lst.insert(lstIt - _pairSize, tmpIt - _pairSize, tmpIt + 1);
                                // std::cerr << "eNTRE TEMPS= " << std::endl;
                                // printPair(tmp);
                                // printPair(lst);
                                break ;
							}
							else if (tmpIt->first <= lstIt->first)
                            {
                                // std::cout << "k = " << k << "; i = " << i << std::endl;
                                // std::cout << "pair = " << _pairSize <<"; k = " << k << "; i= " << i << "; tmpit  = " << tmpIt->first << "; lstit  = " << lstIt->first << std::endl;
                                // typename T::iterator tmpitbegin = tmp.begin();
                                // typename T::iterator tmpitend = tmp.begin();
                                typename T::iterator tmpitbegin =  tmpIt - (_pairSize - 1);
                                typename T::iterator tmpitend = tmpIt + 1;
                                typename T::iterator lstitpos;
                                // if (lstIt != lst.begin() && _pairSize != 1)
                                //     lstitpos = lstIt - 1;
                                // else
                                lstitpos = lstIt - (_pairSize - 1);
                                // typename T::iterator lstitpos = lst.begin();
                                // std::advance(tmpitbegin, (k - 1) * _pairSize);
                                // std::advance(tmpitend, k * _pairSize);
                                // std::advance(lstitpos, i * _pairSize);
                                std::cout << "valeur de lst ou on va se positionner = " << lstitpos->first << std::endl;
                                std::cout <<"valeur de debut de tmp a indroduire = " << tmpitbegin->first << std::endl;
                                // changeValue<T>(tmpitbegin, tmpitend);
								lst.insert(lstitpos, tmpitbegin, tmpitend);
                                // lst.insert(lstIt - _pairSize, tmpIt - _pairSize, tmpIt + 1);
                                // std::cerr << "eNTRE TEMPS= " << std::endl;
                                // printPair(tmp);
                                // printPair(lst);
                                break ;
                            }
                        }
                    }
                }
            }
            std::cerr << "APRES (2eme liste doit contenir la première)= " << std::endl;
            printPair(tmp);
            printPair(lst);
        }

        // template <typename T>
        // typename T::iterator deleteBloc(int value, T &tmp, T&pend)
        // {
        // //     if (!pend.empty())
        // //     {
        // //         std::cout << "delete pend bef";
        // //         printCont(pend);
        // //     }
        //     tmp.clear();

		// 	printPair(pend);
        //     typename T::iterator it = pend.begin();
        //     while (it != pend.end() && it->second.second <= value)
        //     {
		// 		std::cout << "ICI it->first = " << it->first << "; it->second.second = " << it->second.second << std::endl;
        //         if (it->second.second <= value)
        //             it = pend.erase(it);
        //         else
        //             it = it + 1;
		// 			// it = pend.erase(it, pend.end());
        //     }
        //     // if (!pend.empty())
        //     // {
        //     //     std::cout << "delete pend aft";
        //     //     printCont(pend);
        //     // }
        //     return (it);
        // }

		template <typename T>
        typename T::iterator deleteBloc(int value, T &tmp, T&pend)
        {
        //     if (!pend.empty())
        //     {
        //         std::cout << "delete pend bef";
        //         printCont(pend);
        //     }
			// typename T::iterator it;
            // tmp.clear();
			// // int k = 1;
			// printPair(pend);
			// for (it = pend.begin() + (_pairSize - 1); it != pend.end(); it += _pairSize - 1)
            // // while (it != pend.end() && it->second.second <= value)
            // {
			// 	std::cout << "ICI it->first = " << it->first << "; it->second.second = " << it->second.second << std::endl;
            //     if (it->second.second <= value)
            //         it = pend.erase(it - (_pairSize - 1), it + 1);
            //     // else
            //     //     it = it + 1;
			// 		// it = pend.erase(it, pend.end());
            // }
            // // if (!pend.empty())
            // // {
            // //     std::cout << "delete pend aft";
            // //     printCont(pend);
            // // }

            tmp.clear();
			// std::cerr << "AV Delte Bloc; value = " << value << "; bloc pend = " << std::endl;
            // printCont(pend);
			// printPair(pend);
            typename T::iterator it = pend.begin();
			int f = 0;
            while (it != pend.end() && it->second.second <= value && f == 0)
            {
                if (it->second.second <= value)
				{
					if (it->second.second == value)
						f = 1;
                    it = pend.erase(it);

				}
                else
                    ++it;
            }
            // if (!pend.empty())
            // {
            //     std::cout << "delete pend aft";
            //     printCont(pend);
            // }
            // std::cerr << "AP r = " << _pairSize << "pend = ";
            // printCont(pend);


            return (it);
        }



        template <typename T>
        void insertPend(T &lst, T &pend)
        {
            int jacob;
            int last_v = getLastInd(pend);
            int v = 0;
            T tmp;
            // size_t k = 1;
            // size_t i = 0;

            (void) lst;
            jacob = jacobNb(3 + v); //il faut etre dnas une boucle et metre a jour v
            //tant que pend non vide on fait ca
            // std::cerr << "last-v = " << last_v << " jacob = " << jacob << std::endl;
            // std::cout << "move ";
            // printCont(pend);
            // for (typename T::iterator it = pend.begin(); it != pend.end(); ++it)
            // {
            //     if (it->second.second == last_v || it->second.second == jacob)
            //     {
            //         tmp = createBloc(it->second.second, pend);
            //         insertBloc(lst, tmp);
            //         std::cout << "like";
            //         printCont(pend);
            //         it = deleteBloc(it->second.second, tmp, pend);
            //         break;
            //     }
            // } // ci dessous a decommenter

            while (pend.empty() != true)
            {
                typename T::iterator it = pend.begin();
                while (it != pend.end()) //ne sert a rien en soit
                {
                    if (it->second.second == jacob) //mise à jour du nombre de jacobsthal
                    {
                        tmp = createBloc(it->second.second, pend); // autre liste inversee
                        std::cout << "r = " << _pairSize << " y BEFORE = ";
                        printCont(tmp);
                        printCont(pend);
                        printCont(lst);
                        insertBloc(lst, tmp); //insert dans liste
                        std::cout << "BETWIN (lst doit être complète ici) = ";
                        printCont(tmp);
                        printCont(pend);
                        printCont(lst);
                        it = deleteBloc(it->second.second, tmp, pend); //delete bloc et temp
                        // k--;
                        v++;
                        jacob = jacobNb(3 + v);
                        std::cout << "AFTER (pend + lst = total) = ";
                        printCont(tmp);
                        printCont(pend);
                        printCont(lst);
                        // std::cout << "ici" << std::endl;
                        break;
                    }
                    else if (it->second.second == last_v)
                    {
                        std::cout << "puis la" << std::endl;
						std::cout << "r = " << _pairSize << " y BEFORE = ";
                        printCont(tmp);
                        printCont(pend);
                        printCont(lst);
                        tmp = createBloc(last_v, pend); // autre liste inversee
                        insertBloc(lst, tmp); //insert dans liste
						std::cout << "BETWIN (lst doit être complète ici) = ";
                        printCont(tmp);
                        printCont(pend);
                        printCont(lst);
                        it = deleteBloc(last_v, tmp, pend); //delete bloc et temp
                        std::cout << "AFTER (pend + lst = total) = ";
                        printCont(tmp);
                        printCont(pend);
                        printCont(lst);
						break;
                    }
                    else
                        ++it;
                    // la valeur est la derniere, on recule jusqu'au debut (on enleve ce qu'on place)
                    // while (k * _pairSize - 1 >= _pairSize - 1) //faut mettre a jour k et j ai un doute ici
                    // {
                    //     insertBloc();//on trie tout jusquau début
                    // }

                    // if (i == k * _pairSize - 1)
                    //     k++;
                    // i++;
                }
            }



        }

        template <typename T>
        void mergeInsert(T &lst)
        {
            int f = 0;

            // std::cout << "j0  = " << jacobNb(0) << std::endl;
            // std::cout << "dishes "
            // _pairSize /= 2; //pour le premier on est a 8
			std::cout << "r en debut de deuxieme partie = " << _pairSize << std::endl;
            while (_pairSize >= 1)
            {
                // std::cout << "r = " << _pairSize << " size = " <<lst.size() << std::endl;
                if (f == 0 && _pairSize * 3 > lst.size()) // revoir caaa utile ??
                {
					std::cout << "dishes " << std::endl;
                    // std::cout << "r = " << _pairSize << " et on a passe" << std::endl;
                    _pairSize /= 2; //pour le premier on est a 8
                    // f = 1;
                    continue;
                }
                // std::cout << "verif r = " << _pairSize << std::endl;
				T remain;
                T pend = createPend(lst, remain); // on recupere le reste dans un tableau

                printCont(pend);
                printCont(lst);
                insertPend(lst, pend);
				lst.insert(lst.end(), remain.begin(), remain.end());
				remain.clear();
				// on remet le reste dans lst et on supprime le reste
                _pairSize /= 2; //pour le premier on est a 8
				std::cerr << "TOUTE FIN DE TOUR = " << std::endl;
            	printPair(lst);
                // f = 1;
            }
            _pairSize = 1;
        }















        template <typename T>
        void printCont(T &lst) const
        {
            std::cout << "container:";
            for (typename T::const_iterator it = lst.begin(); it != lst.end(); ++it)
                std::cout << it->first << " ";
            std::cout << std::endl;
        }


        template <typename T>
        void printPair(const T &lst) // surement a supprimer a la fin
        {
            std::cout << "container de pair:";
            for (typename T::const_iterator it = lst.begin(); it != lst.end(); ++it)
            {
                 std::cout << "(" << it->first << ",(" << it->second.first << "," << it->second.second << ")) ";
            }
            std::cout << std::endl;
        }

        // void insertPend(std::vector<int> &lst, std::vector<int> &pend);
        // void insertPend(std::deque<int> &lst, std::deque<int> &pend);

        int jacobNb(int n);
        // int getJacobNb(int n);

        void print(int n) const;

    private:
        std::vector< std::pair<int, std::pair<char, int> > > _vect;
        std::deque < std::pair<int, std::pair<char, int> > > _deq;
        size_t _pairSize;

        PmergeMe();

} ;

#endif
