#include "Brain.hpp"

//constructors and destructor
Brain::Brain()
{
    for (int i = 0; i < 100; ++i)
        this->_ideas[i] = "Great idea";
    std::cout << "A brain is created with great ideas" << std::endl;
}

Brain::Brain(const Brain &other)
{
    for (int i = 0; i < 100; ++i)
        this->_ideas[i] = other._ideas[i];
    std::cout << "A brain is created by copying another one" << std::endl;
}

Brain::~Brain()
{
    std::cout << "The brain is destroyed" << std::endl;
}

//operators
Brain   &Brain::operator=(const Brain &other)
{
    if (this == &other)
        return (*this);
    for (int i = 0; i < 100; ++i)
        this->_ideas[i] = other._ideas[i];
    return (*this);
}

//public member funcs
std::string *Brain::getIdeas()
{
    return (this->_ideas);
}