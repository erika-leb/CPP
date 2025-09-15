#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}
ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void) src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void) rhs;
	return (*this);
}

static bool isChar(const std::string &str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return (true);
	return (false);
}

static bool isInt(const std::string &str)
{
	char *end;

	long v = std::strtol(str.c_str(), &end, 10);
	if (*end == '\0' && v >= INT_MIN && v <= INT_MAX )
		return (true);
	return (false);
}

static bool isFloat(const std::string &str)
{
	char *end;
	double v;

	if (str == "nanf" || str == "+inff" || str =="-inff")
		return (true);
	v = std::strtof(str.c_str(), &end);
	if (*end == 'f' && *(end + 1) == '\0' && *(end - 1) != '.')
		return (true);
	return (false);
}

static bool isDouble(const std::string &str)
{
	char *end;
	double v;

	if (str == "nan" || str == "+inf" || str =="-inf")
		return (true);
	v = std::strtod(str.c_str(), &end);
	if (*(end) == '\0' && *(end - 1) != '.')
		return (true);
	return (false);
}

static void printChar(const char c)
{
	if (isprint(static_cast<unsigned char>(c)) == false)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<const int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<const float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<const double>(c) << std::endl;
}

static void printInt(const int n)
{
	if (isprint(static_cast<unsigned char>(n)) == false) //soucis ici ?
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	std::cout << "int: " << static_cast<const int>(n) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<const float>(n) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<const double>(n) << std::endl;
}

static void printFloat(const float f)
{
	if (std::isinf(f) == true || std::isnan(f) == true)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		if (isprint(static_cast<unsigned char>(f)) == false)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
		std::cout << "int: " << static_cast<const int>(f) << std::endl;
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<const float>(f) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<const double>(f) << std::endl;
}

static void printDouble(const double d)
{
	if (std::isinf(d) == true || std::isnan(d) == true)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		if (isprint(static_cast<unsigned char>(d)) == false)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
		std::cout << "int: " << static_cast<const int>(d) << std::endl;
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<const float>(d) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<const double>(d) << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
	if (isChar(str) == true)
		printChar(static_cast<char>(str[0]));
	else if (isInt(str) == true)
		printInt(static_cast<int>(std::strtol(str.c_str(), NULL, 10)));
	else if (isFloat(str) == true)
		printFloat(static_cast<float>(std::strtof(str.c_str(), NULL)));
	else if (isDouble(str) == true)
		printDouble(static_cast<double>(std::strtod(str.c_str(), NULL)));
	else
		std::cout << "Invalid literal" << std::endl;
}
