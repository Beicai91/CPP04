#include "Animal.hpp"

//constructors and destructor
Animal::Animal(): _type("Default")
{
    std::cout << "A default animal is created" << std::endl;
}

Animal::Animal(std::string type): _type(type)
{
    std::cout << "An animal of type " << this->_type << " is created" << std::endl;
}

Animal::Animal(const Animal &other): _type(other._type)
{
    std::cout << "An animal of type " << this->_type << " is created by copying another animal" << std::endl;
}

Animal::~Animal()
{
    std::cout << "The animal is detroyed" << std::endl;
}

//operators
Animal  &Animal::operator=(const Animal &other)
{
    if (this == &other)
        return (*this);
    this->_type = other._type;
    return (*this);
}

//public member funcs
void    Animal::makeSound() const
{
    std::cout << "The animal is making sound" << std::endl;
}

std::string Animal::getType() const
{
    return (this->_type);
}