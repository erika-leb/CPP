#include "iter.hpp"

// void printInt(int &x) {
// 	std::cout << x << " ";
// }

// int main() {
// 	int arr[5] = {1, 2, 3, 4, 5};
// 	iter(arr, 5, printInt);
// 	std::cout << std::endl;
// }

#include <sstream>

void	upChar(char &c)
{
	c = std::toupper(c);
}

int	main(void)
{

	std::string	str = "Coucou petite perruche";

	std::cout << "Before iter: " << str << std::endl;
	iter(&str[0], str.length(), upChar);
	std::cout << "After iter: " << str << std::endl;

	return (0);
}
