#include "Dog.hpp"

//constructors and destructor
Dog::Dog():Animal()
{
    this->_type = "Default(dog)";
    std::cout << "A default dog is created" << std::endl;
}

Dog::Dog(std::string type): Animal(type)
{
    this->_type = type;
    std::cout << "A " << type << " dog is created" << std::endl;
}

Dog::Dog(const Dog &other): Animal(other)
{
    this->_type = other._type;
    std::cout << "A " << this->_type << " dog is created by copying another one" << std::endl;
}

Dog::~Dog()
{
    std::cout << "The " << this->_type << " dog is destroyed" << std::endl;
}

//operators
Dog &Dog::operator=(const Dog &other)
{
    if (this == &other)
        return (*this);
    Animal::operator=(other);
    this->_type = other._type;
    return (*this);
}

//public member funcs
void    Dog::makeSound() const
{
    std::cout << "The " << this->_type << " dog is barking" << std::endl;
}