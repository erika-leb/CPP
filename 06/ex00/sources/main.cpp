#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
        ScalarConverter::convert(argv[1]);
    else
        std::cout << "Need one argument" << std::endl;
    return 0;
}


// verifier s il y a un argumen ""
//gerer les signes - ou + un seul sans espace
