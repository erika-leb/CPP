#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        _inv[i] = NULL;
    std::cout << "MateriaSource constructor called" << std::endl;
}
MateriaSource::MateriaSource(const MateriaSource &src)
{
    for (int i = 0; i < 4; i++)
    {
        if (src._inv[i])
            _inv[i] = src._inv[i]->clone();
        else
            _inv[i] = NULL;
    }
    std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (_inv[i])
        {
            delete _inv[i];
            _inv[i] = NULL;
        }
    }
    std::cout << "MateriaSource destructor called" << std::endl;
}

const MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
    std::cout << "MateriaSource constructor called" << std::endl;
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_inv[i])
            {
                delete _inv[i];
                _inv[i] = NULL;
            }
            if (rhs._inv[i])
                _inv[i] = rhs._inv[i]->clone();
            else
                _inv[i] = NULL;
        }
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria*m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!_inv[i])
        {
            _inv[i] = m;
            return ;
        }
    }
    std::cout << "no room left for new materia. Materia destroyed" << std::endl;
    delete m; //doute ICI aussi ici du coup
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_inv[i] && type == _inv[i]->getType())
            return (_inv[i]->clone());
    }
    std::cout << "Materia not found in inventory" << std::endl;
    return NULL;
}
