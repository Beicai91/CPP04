#ifndef CAT_HPP
# define CAT_HPP

#include "A_Animal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

class Cat: public Animal
{
    private:
        Brain   *_catBrain;

    public:
        Cat();
        Cat(std::string type);
        Cat(const Cat &other);
        Cat &operator=(const Cat &other);
        ~Cat();
        void    makeSound() const;
        void    printIdeas();
        Brain   *getBrain();
};

#endif