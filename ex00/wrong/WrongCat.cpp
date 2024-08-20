
#include "WrongCat.hpp"

//constructors and destructor
WrongCat::WrongCat(): WrongAnimal()
{
    this->_type = "Default(cat)";
    std::cout << "A default cat is created" << std::endl;
}

WrongCat::WrongCat(std::string type): WrongAnimal(type)
{
    this->_type = type;
    std::cout << "A " << type << " cat is created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other)
{
    this->_type = other._type;
    std::cout << "A " << this->_type << " cat is created by copying another one" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "The " << this->_type << " cat is destroyed" << std::endl;
}

//operators
WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if (this == &other)
        return (*this);
    WrongAnimal::operator=(other);
    this->_type = other._type;
    return (*this);
}

void    WrongCat::makeSound() const
{
    std::cout << "The " << this->_type << " cat is purring" << std::endl;
}