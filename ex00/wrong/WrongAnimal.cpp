
#include "WrongAnimal.hpp"

//constructors and destructor
WrongAnimal::WrongAnimal(): _type("Default")
{
    std::cout << "A default animal is created" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type)
{
    std::cout << "An animal of type " << this->_type << " is created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other): _type(other._type)
{
    std::cout << "An animal of type " << this->_type << " is created by copying another animal" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "The animal is detroyed" << std::endl;
}

//operators
WrongAnimal  &WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this == &other)
        return (*this);
    this->_type = other._type;
    return (*this);
}

//public member funcs
void    WrongAnimal::makeSound() const
{
    std::cout << "The animal is making sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->_type);
}