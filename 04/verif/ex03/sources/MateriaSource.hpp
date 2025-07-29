#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class AMateria;

class MateriaSource : public IMateriaSource {

    public:
        MateriaSource();
        MateriaSource(const MateriaSource &src);
        ~MateriaSource();
        const MateriaSource &operator=(const MateriaSource &rhs);

        void learnMateria(AMateria*m);
        AMateria* createMateria(std::string const & type);
    
    private:
        AMateria *_inv[4];
} ;


#endif
