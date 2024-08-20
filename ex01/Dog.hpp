#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

class Dog: public Animal
{
    private:
        Brain   *_dogBrain;

    public:
        Dog();
        Dog(std::string type);
        Dog(const Dog &ther);
        Dog &operator=(const Dog &other);
        ~Dog();
        void    makeSound() const;
        void    printIdeas();
};

#endif