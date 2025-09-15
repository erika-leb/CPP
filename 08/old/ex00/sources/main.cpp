#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
    try {
        std::vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);

        std::list<int> l;
        l.push_back(100);
        l.push_back(200);
        l.push_back(300);

        // Cherche 20 dans le vecteur
        std::vector<int>::iterator it = easyfind(v, 20);
        std::cout << "Found in vector: " << *it << std::endl;

        // Cherche 400 dans la liste (va échouer)
        std::list<int>::iterator it2 = easyfind(l, 400);
        std::cout << "Found in list: " << *it2 << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
