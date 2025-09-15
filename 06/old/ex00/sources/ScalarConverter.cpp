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
	double value;

	value = std::strtol(str.c_str(), &end, 10);
	if (*end == '\0' && value >= INT_MIN && value <= INT_MAX)
		return (true);
	return (false);
}

static bool isFloat(const std::string &str)
{
	char *end;

	if (str == "nanf" || str == "+inff" || str == "-inff")
		return (true);
	std::strtof(str.c_str(), &end);
	if (*end == 'f' && *(end + 1) == '\0' && *(end - 1) != '.') //est-ce que ca marche pour 40f ?
		return (true);
	return (false);
}

static bool isDouble(const std::string &str)
{
	char *end;

	if (str == "nan" || str == "+inf" || str == "-inf")
		return (true);
	std::strtod(str.c_str(), &end);
	if (*(end + 1) == '\0' && *(end - 1) != '.')
		return (true);
	return (false);
}

static void printChar(const char c)
{
	if (!isprint(c))
		std::cout << "char: Non displayable" <<std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

static void printInt(const int n)
{
	if (!isprint(n))
		std::cout << "char: Non displayable" <<std::endl;
	else
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
}

static void printFloat(const float f)
{
	if (std::isinf(f) || std::isnan(f))
	{
		std::cout << "char: impossible" <<std::endl;
		std::cout << "int: mpossible" <<std::endl;
	}
	else
	{
		if (!isprint(f))
			std::cout << "char: Non displayable" <<std::endl;
		else
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
}

static void printDouble(const double d)
{
if (std::isinf(d) || std::isnan(d))
	{
		std::cout << "char: impossible" <<std::endl;
		std::cout << "int: mpossible" <<std::endl;
	}
	else
	{
		if (!isprint(d))
			std::cout << "char: Non displayable" <<std::endl;
		else
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<int>(d) << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;}

void ScalarConverter::convert(const std::string &str)
{
	if (isChar(str) == true)
		printChar((str[0]));
	else if(isInt(str) == true)
		printInt(std::atoi(str.c_str()));
	else if(isFloat(str) == true)
		printFloat(std::strtof(str.c_str(), NULL));
	else if(isDouble(str) == true)
		printDouble(std::strtof(str.c_str(), NULL));
	else
		std::cout << "Invalid literal" << std::endl;
}

