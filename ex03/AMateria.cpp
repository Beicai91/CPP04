#include "AMateria.hpp"
#include "Character.hpp"

//constructors and destructor
AMateria::AMateria(std::string const &type): _type(type)
{}

AMateria::AMateria(const AMateria &other): _type(other._type)
{}

AMateria::~AMateria()
{}

//public member funcs
std::string const   &AMateria::getType() const
{
    return (this->_type);
}

void    AMateria::use(ICharacter &target)
{
    std::cout << this->_type << " used on " << target.getName() << std::endl;
}