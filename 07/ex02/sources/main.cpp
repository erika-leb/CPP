#include <iostream>
#include <cstdlib>
#include "Array.hpp"
#include "Array.tpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
		// std::cout << numbers[2] << std::endl;
        numbers[-2] = 0;
		// std::cout << numbers[2] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}


// #include <iostream>
// #include <string>
// #include <cstdlib>
// #include "Array.hpp"
// #include "Array.tpp"

// int main() {
//     std::cout << "=== Test constructeur par défaut ===" << std::endl;
//     Array<int> empty;
//     std::cout << "Taille empty : " << empty.size() << std::endl;

//     std::cout << "\n=== Test constructeur avec taille ===" << std::endl;
//     Array<int> numbers(5);
//     for (unsigned int i = 0; i < numbers.size(); i++)
//         numbers[i] = i * 10;

//     for (unsigned int i = 0; i < numbers.size(); i++)
//         std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;

//     std::cout << "\n=== Test constructeur par copie ===" << std::endl;
//     Array<int> copyNumbers(numbers);
//     std::cout << "Avant modification copyNumbers[2] = 99" << std::endl;
//     copyNumbers[2] = 99;

//     std::cout << "numbers[2] = " << numbers[2] << " (doit rester inchangé)" << std::endl;
//     std::cout << "copyNumbers[2] = " << copyNumbers[2] << std::endl;

//     std::cout << "\n=== Test opérateur d'affectation ===" << std::endl;
//     Array<int> assignNumbers;
//     assignNumbers = numbers;
//     assignNumbers[1] = 77;

//     std::cout << "numbers[1] = " << numbers[1] << " (inchangé)" << std::endl;
//     std::cout << "assignNumbers[1] = " << assignNumbers[1] << std::endl;

//     std::cout << "\n=== Test accès hors limites ===" << std::endl;
//     try {
//         std::cout << numbers[10] << std::endl;
//     } catch (const std::exception &e) {
//         std::cerr << "Exception catchée : " << e.what() << std::endl;
//     }

//     try {
//         numbers[5] = 123;
//     } catch (const std::exception &e) {
//         std::cerr << "Exception catchée : " << e.what() << std::endl;
//     }

//     try {
//         numbers[-1] = 42; // attention, le paramètre est unsigned => conversion wrap-around
//     } catch (const std::exception &e) {
//         std::cerr << "Exception catchée : " << e.what() << std::endl;
//     }

//     std::cout << "\n=== Test avec type autre que int ===" << std::endl;
//     Array<std::string> words(3);
//     words[0] = "hello";
//     words[1] = "world";
//     words[2] = "42";

//     for (unsigned int i = 0; i < words.size(); i++)
//         std::cout << "words[" << i << "] = " << words[i] << std::endl;

//     std::cout << "\n=== Fin des tests ===" << std::endl;

//     return 0;
// }
