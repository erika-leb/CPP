#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {

	public:
		Brain();
		Brain(const Brain &src);
		~Brain();
		Brain &operator=(const Brain &rhs);

		std::string getIdea(const int i) const;
		void setIdea(const int i, const std::string idea);

		private:
			std::string ideas[100];
} ;

#endif
