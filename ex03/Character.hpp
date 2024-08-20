#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character: public ICharacter
{
    private:
        AMateria    *_inventory[4];
        std::string _name;
    
    public:
        Character(std::string name);
        Character(const Character &other);
        Character   &operator=(const Character &other);
        ~Character();
        std::string const   &getName() const;
        void    equip(AMateria *m);
        void    unequip(int idx);
        void    use(int idx, ICharacter &target);
        //this function is added for handling memory of a materia when a character unequip it
        AMateria    *getInventoryMateria(int idx);
};

#endif