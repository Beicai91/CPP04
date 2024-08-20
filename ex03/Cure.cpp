
#include "Cure.hpp"

//constructors and destructor
Cure::Cure(): AMateria("Cure")
{
    this->_type = "cure";
}

Cure::Cure(const Cure &other): AMateria(other)
{}

Cure::~Cure()
{}

//operator
Cure &Cure::operator=(const Cure &other)
{
    if (this == &other)
        return (*this);
    AMateria::operator=(other);
    this->_type = other._type;
    return (*this);
}

//public member funcs
AMateria    *Cure::clone() const
{
    return (new Cure());
}

void    Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}