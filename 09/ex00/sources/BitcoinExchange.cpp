#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string data)
{
	std::ifstream file(data.c_str());
	std::string line;
	std::string date;
	std::string val;
	float value;

	if (!file)
		throw std::runtime_error("could not open file");
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::getline(iss, date, ',');
		std::getline(iss, val);
		value = std::strtof(val.c_str(), NULL);
		_data[date] = value;
		// std::cout << date << " : " << value << std::endl;
	}
	// for (std::map<std::string, float>::iterator j = data.begin() ; j != data.end() ; ++j)
		// std::cout << j->first << " = " << j->second << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : _data(src._data)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
		_data = rhs._data;
	return (*this);
}

void BitcoinExchange::parseInput(std::string date, float value) const
{
	std::istringstream iss(date);
	std::string year;
	float y;
	float z;

	std::getline(iss, year, '-');
	if (date.size() != 11 || date[4] != '-' || date[7] != '-')
		throw std::invalid_argument("Error: bad input => " + date);
	y = std::strtof(year.c_str(), NULL);
	if (y < 1000 || y > 9999)
		throw std::invalid_argument("Error: bad input => " + date);
	std::getline(iss, year, '-');
	y = std::strtof(year.c_str(), NULL);
	if (y < 1 || y > 12)
		throw std::invalid_argument("Error: bad input => " + date);
	std::getline(iss, year);
	z = std::strtof(year.c_str(), NULL);
	if ((y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12) && (z < 0 || z > 31))
		throw std::invalid_argument("Error: bad input => " + date);
	if ((y == 4 || y == 6 || y == 9 || y == 11) && (z < 0 || z > 30))
		throw std::invalid_argument("Error: bad input => " + date);
	if (y == 2 && (z < 0 || z > 28))
		throw std::invalid_argument("Error: bad input => " + date);
	// std::cout << "value =" << value << std::endl;
	if (value < 0)
		throw std::out_of_range("Error: not a positive number");
	if (value > 1000)
		throw std::out_of_range("Error: too large number");
}

float BitcoinExchange::getRate(std::string date) const
{
	// std::cout << "date = " << date << "lll" << std::endl; // a effacer apres
	std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
	// std::string it = _data.lower_bound(date)-> first;
	if (it == _data.begin())
		return (it->second);
	if (it == _data.end() || it->first != date)
	{
		--it;
		return (it->second);
	}
	// for (std::map<std::string, float>::const_iterator it = _data.begin(); it != _data.end(); ++it)
	// {
	// 	ret
	// }
	// return (0);
	// std::cout << "voila:" << (_data.lower_bound(date))->second << std::endl;

	return (it->second);
	}

void BitcoinExchange::processInput(char *input)
{
	std::ifstream file(input);
	std::string line;
	std::string date;
	std::string val;
	float value;
	float rate;

	if (!file)
		throw std::runtime_error("could not open file");
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::getline(iss, date, '|');
		std::getline(iss, val);
		if (date == "date ") // doute ici
			continue;
		value = std::strtof(val.c_str(), NULL);
		// std::cout << date << " : " << value << std::endl;
		try {
			parseInput(date, value);
			rate = getRate(date); //a faire
			// std::cout << date << "=> " << value << " = " << std::fixed << std::setprecision(2) << rate * value  << std::endl; // a verifier
			std::cout << date << "=> " << value << " = " << rate * value  << std::endl; // a verifier

		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
