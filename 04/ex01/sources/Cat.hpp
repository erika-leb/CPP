#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {

	public:
		Cat();
		Cat(const Cat &src);
		~Cat();
		Cat &operator=(const Cat &rhs);

		void setIdeas(const int i, const std::string idea);
		std::string getIdeas(const int i) const;
		void makeSound() const;
		void printBrain(void);

	private:
		Brain *_brain;

} ;

#endif
