# include "RPN.hpp"

RPN::RPN(std::string str) : _str(str)
{
}

RPN::RPN(const RPN &src)
{
	(void) src;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &rhs)
{
	(void) rhs;
	return (*this);
}

RPN::RPN()
{
}

void RPN::calculate()
{
	for (size_t i = 0; i < _str.size(); i++)
	{
		int op1;
		int op2;

		if (_str[i] >= '0' && _str[i] <= '9')
			_nb.push(_str[i] - '0');
		else if (_str[i] == ' ')
			continue;
		else if (_str[i] == '+' || _str[i] == '-' || _str[i] == '/' || _str[i] == '*')
		{
			if (_nb.empty())
				throw std::invalid_argument("");
			op2 = _nb.top();
			_nb.pop();
			if (_nb.empty())
				throw std::invalid_argument("");
			op1 = _nb.top();
			_nb.pop();
			if (_str[i] == '+')
				_nb.push(op1 + op2);
			if (_str[i] == '-')
				_nb.push(op1 - op2);
			if (_str[i] == '/')
			{
				if(op2 == 0)
					throw std::invalid_argument("");
				_nb.push(op1 / op2);
			}
			if (_str[i] == '*')
				_nb.push(op1 * op2);
		}
		else
			throw std::invalid_argument("");
	}
	int res = _nb.top();
	_nb.pop();
	if (!_nb.empty())
		throw std::invalid_argument("");
	std::cout << res << std::endl;
}
