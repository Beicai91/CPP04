#include "Cat.hpp"

//constructors and destructor
Cat::Cat(): Animal(), _catBrain(new Brain())
{
    this->_type = "Default(cat)";
    std::cout << "A default cat is created with great ideas" << std::endl;
}

Cat::Cat(std::string type): Animal(type), _catBrain(new Brain())
{
    this->_type = type;
    std::cout << "A " << type << " cat is created with great ideas" << std::endl;
}

Cat::Cat(const Cat &other): Animal(other)
{
    this->_type = other._type;
    this->_catBrain = new Brain(*(other._catBrain));
    std::cout << "A " << this->_type << " cat is created by copying another one" << std::endl;
}

Cat::~Cat()
{
    delete this->_catBrain;
    std::cout << "The " << this->_type << " cat is destroyed" << std::endl;
}

//operators
Cat &Cat::operator=(const Cat &other)
{
    if (this == &other)
        return (*this);
    Animal::operator=(other);
    this->_type = other._type;
    delete this->_catBrain;
    this->_catBrain = new Brain(*(other._catBrain));
    this->_catBrain = other._catBrain;
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << "The " << this->_type << " cat is purring" << std::endl;
}

void    Cat::printIdeas()
{
    std::string *ideas;

    ideas = (*(this->_catBrain)).getIdeas();
    for (int i = 0; i < 100; ++i)
        std::cout << ideas[i] << std::endl;
}

Brain    *Cat::getBrain()
{
    return (this->_catBrain);
}