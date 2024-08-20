#include "Dog.hpp"

//constructors and destructor
Dog::Dog():Animal(), _dogBrain(new Brain())
{
    this->_type = "Default(dog)";
    std::cout << "A default dog is created with great ideas" << std::endl;
}

Dog::Dog(std::string type): Animal(type), _dogBrain(new Brain())
{
    this->_type = type;
    std::cout << "A " << type << " dog is created with great ideas" << std::endl;
}

Dog::Dog(const Dog &other): Animal(other)
{
    this->_type = other._type;
    //deep copy by creating another Brain object
    //`this->_dogBrain = other._dogBrain` is a shallow copy. `this` brain pointer will point to the same memory block as `other` brain pointer, which can lead to double free problem or segfault if one of them is deleted and the other still tries to access
    if (other._dogBrain)
        this->_dogBrain = new Brain(*(other._dogBrain)); // use Brain's copy constructor
    else
        this->_dogBrain = NULL;
    std::cout << "A " << this->_type << " dog is created by copying another one" << std::endl;
}

Dog::~Dog()
{
    delete this->_dogBrain;
    std::cout << "The " << this->_type << " dog is destroyed" << std::endl;
}

//operators
Dog &Dog::operator=(const Dog &other)
{
    if (this == &other)
        return (*this);
    Animal::operator=(other);
    this->_type = other._type;
    //`this` is already a initialised object which has allocated memory for brain. Before deep copying, need to free the previous allocated memory
    delete this->_dogBrain;
    if (other._dogBrain)
        this->_dogBrain = new Brain (*(other._dogBrain));
    else
        this->_dogBrain = NULL;
    return (*this);
}

//public member funcs
void    Dog::makeSound() const
{
    std::cout << "The " << this->_type << " dog is barking" << std::endl;
}

void    Dog::printIdeas()
{
    std::string *ideas = (*(this->_dogBrain)).getIdeas();
    for (int i = 0; i < 100; ++i)
        std::cout << ideas[i] << std::endl;
}