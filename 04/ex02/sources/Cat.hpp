#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {

	public:
		Cat();
		Cat(const Cat &src);
		~Cat();
		Cat &operator=(const Cat &rhs);

		void setIdeas(const int i, const std::string idea);
		std::string getIdeas(const int i) const;
		void makeSound() const;

	private:
		Brain *_brain;

} ;

#endif
