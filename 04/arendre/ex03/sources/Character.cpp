#include "Character.hpp"

#include <stdio.h>

Character::Character() : _name("unknown")
{
    for (int i = 0; i < 4; i++)
        _items[i] = NULL;
    for (int j = 0; j < 100; j++)
        _garbage[j] = NULL;
    std::cout << "default Character constructor called" << std::endl;
}

Character::Character(std::string name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        _items[i] = NULL;
    for (int j = 0; j < 100; j++)
        _garbage[j] = NULL;
    std::cout << "Character constructor called" << std::endl;
}

Character::Character(const Character &src) : _name(src._name)
{
    for (int i = 0; i < 4; i++)
    {
        // if (_items[i])
        // {
        //     perror("la");
        //     delete (_items[i]);
        //     perror("lal");
        //     _items[i] = NULL;
        //     perror("lala");
        // }
        if (src._items[i])
            _items[i] = src._items[i]->clone();
        else
            _items[i] = NULL;
    }
    for (int j = 0; j < 100; j++)
    {
        // if (_garbage[j])
        // {
        //     delete (_garbage[j]);
        //     _garbage[j] = NULL;
        // }
        if (src._garbage[j])
            _garbage[j] = src._garbage[j]->clone();
        else
            _garbage[j] = NULL;
    }
    std::cout << "Character copy constructor called" << std::endl;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (_items[i])
            delete (_items[i]);
    }
    for (int j = 0; j < 100; j++)
    {
        if (_garbage[j])
            delete (_garbage[j]);
    }
    std::cout << "Character destructor called" << std::endl;
}

Character &Character::operator=(const Character &rhs)
{
    _name = rhs._name;
    for (int i = 0; i < 4; i++)
    {
        if (_items[i])
        {
            delete (_items[i]);
            _items[i] = NULL;
        }
        if (rhs._items[i])
            _items[i] = rhs._items[i]->clone();
    }
    for (int j = 0; j < 100; j++)
    {
        if (_garbage[j])
        {
            delete (_garbage[j]);
            _garbage[j] = NULL;
        }
        if (rhs._garbage[j])
            _garbage[j] = rhs._garbage[j]->clone();
    }
    std::cout << "Character assignment operator called" << std::endl;
    return (*this);
}

std::string const & Character::getName() const
{
    return (_name);
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!_items[i])
        {
            _items[i] = m;
            std::cout << _items[i]->getType() << " materia equiped on " << _name << " with success" << std::endl;
            return ;
        }
    }
    std::cout << _name << "'s inventory is full ! Materia is destroyed" << std::endl;
    delete m; //doute ICIIIIII
}

void Character::unequip(int idx)
{
    for (int i = 0; i < 4; i++)
    {
        if (i == idx)
        {
            if (!_items[i])
            {
                std::cout << "no materia registered in position " << idx << std::endl;
                return ;
            }
            else
            {
                for (int j = 0; j < 100; j++)
                {
                    if (!_garbage[j])
                    {
                        _garbage[j] = _items[i];
                        _items[i] = NULL;
                        std::cout << _garbage[j]->getType() << " Materia unequiped with success" << std::endl;
                        return ;
                    }
                }
                std::cout << "garbage is full, item cannot be unequiped" << std::endl;
                return ;
            }
        }
    }
    std::cout << "index not valid" << std::endl;  
}

void Character::use(int idx, ICharacter& target)
{
    for (int i = 0; i < 4; i++)
    {
        if (i == idx)
        {
            if (!_items[i])
            {
                std::cout << "no item registered at position " << idx << std::endl;
                return ;
            }
            else
            {
                _items[i]->use(target);
                return ;
            }
        }
    }
    std::cout << "index not valid" << std::endl;
}