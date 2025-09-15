#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <stdlib.h>
# include <sstream>
# include <algorithm>
# include <iomanip>

class BitcoinExchange {

	public :
		BitcoinExchange(std::string data);
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &rhs);

		void processInput(char *input);

	private :
		std::map<std::string, float> _data;
		BitcoinExchange();

		void parseInput(std::string date, float value) const;
		float getRate(std::string date) const;
} ;

#endif
