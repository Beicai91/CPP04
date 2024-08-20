#include "Ice.hpp"

//constructors and destructor
Ice::Ice(): AMateria("ice")
{
    this->_type = "ice";
}

Ice::Ice(const Ice &other): AMateria(other)
{}

Ice::~Ice()
{}

//operator
Ice &Ice::operator=(const Ice &other)
{
    if (this == &other)
        return (*this);
    AMateria::operator=(other);
    this->_type = other._type;
    return (*this);
}

//public member funcs
AMateria    *Ice::clone() const
{
    return (new Ice());
}

void    Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}