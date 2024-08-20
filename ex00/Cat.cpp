#include "Cat.hpp"

//constructors and destructor
Cat::Cat(): Animal()
{
    this->_type = "Default(cat)";
    std::cout << "A default cat is created" << std::endl;
}

Cat::Cat(std::string type): Animal(type)
{
    this->_type = type;
    std::cout << "A " << type << " cat is created" << std::endl;
}

Cat::Cat(const Cat &other): Animal(other)
{
    this->_type = other._type;
    std::cout << "A " << this->_type << " cat is created by copying another one" << std::endl;
}

Cat::~Cat()
{
    std::cout << "The " << this->_type << " cat is destroyed" << std::endl;
}

//operators
Cat &Cat::operator=(const Cat &other)
{
    if (this == &other)
        return (*this);
    Animal::operator=(other);
    this->_type = other._type;
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << "The " << this->_type << " cat is purring" << std::endl;
}