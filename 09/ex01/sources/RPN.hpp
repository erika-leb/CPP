#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class RPN {

	public:
		RPN(std::string str);
		RPN(const RPN &src);
		~RPN();

		void calculate();

	private:
		std::string _str;
		std::stack<int> _nb;
		RPN();
		RPN &operator=(const RPN &rhs);
} ;


#endif
