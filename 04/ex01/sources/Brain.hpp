#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {

	public:
		Brain();
		Brain(const Brain &src);
		~Brain();
		Brain &operator=(const Brain &rhs);

		void setIdea(int idx, std::string idea);
		std::string getIdea(int idx) const;

	private:
		std::string _ideas[100];

} ;

#endif
