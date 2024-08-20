#ifndef A_ANIMAL_HPP
# define A_ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
    protected:
        std::string _type;

    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal &other);
        Animal  &operator=(const Animal &other);
        virtual ~Animal();
        virtual void    makeSound() const = 0;
        std::string    getType() const;
};


#endif