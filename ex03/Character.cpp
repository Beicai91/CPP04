#include "Character.hpp"

//constructors and destructor
Character::Character(std::string name):_name(name)
{
    for (int i = 0; i < 4; ++i)
        this->_inventory[i] = NULL;
}

Character::Character(const Character &other): _name(other._name + "_copy")
{
    //deep copy!!
    for (int i = 0; i < 4; ++i)
    {
        if (other._inventory[i])
            this->_inventory[i] = (other._inventory[i])->clone();
        else
            this->_inventory[i] = NULL;
    }
}

Character::~Character()
{ 
    std::cout << "detroying " << this->_name << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        if (this->_inventory[i])
        {
            std::cout << "deleting inventory N." << i << (this->_inventory[i])->getType() << std::endl;
            delete this->_inventory[i];
            this->_inventory[i] = NULL;
        }
    }
    std::cout << "  ->destroyed" << std::endl;
}

//operator
Character   &Character::operator=(const Character &other)
{
    if (this == &other)
        return (*this);
    //delete `this` previous allocated memory
    for (int i = 0; i < 4 && this->_inventory[i]; ++i)
    {
        delete this->_inventory[i];
        this->_inventory[i] = NULL;
    }
    //deep copy!!
    for (int i = 0; i < 4; ++i)
    {
        if (other._inventory[i])
            this->_inventory[i] = (other._inventory[i])->clone();
    }
    return (*this);
}

//public member funcs
std::string const   &Character::getName() const
{
    return (this->_name);
}

void    Character::equip(AMateria *m)
{
    int i;
    
    i = 0;
    while (this->_inventory[i])
        i++;
    if (i < 4)
    {
        this->_inventory[i] = m;
        std::cout << "Slot N." << i << " is equiped with " << m->getType() << std::endl;
    }
    else
    {
        std::cout << "All slots are full. Impossible to equipe extra materia" << std::endl;
        std::cout << this->_name << ": If I can't take it, nobody else can get it. Destroying..." << std::endl;
        delete m;
        std::cout << "The materia is destroyed" << std::endl;
    }
}

void    Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
    {
        if (this->_inventory[idx])
        {
            this->_inventory[idx] = NULL;
            std::cout << "Slot N." << idx << " is unequipped" << std::endl;
        }
        else
            std::cout << "Slot N." << idx << " is already empty. Nothing to unequip" << std::endl;
    }
    else
        std::cout << "Invalid slot" << std::endl;
}

void    Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= 4 || !this->_inventory[idx])
    {
        std::cout << "Impossible to use materia: invalid slot index or slot is empty" << std::endl;
        return ;
    }
    (this->_inventory[idx])->use(target);
}

AMateria    *Character::getInventoryMateria(int idx)
{
    //test
    //std::cout << "inside getInventoryMateria func" << std::endl;
    //
    return (this->_inventory[idx]);
}
