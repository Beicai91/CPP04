#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    /*
    //create some default objects of each class
    Animal  animal;
    Dog doggie;
    Cat kitty;

    std::cout << "\n" << std::endl;
    //create some specific objects
    Dog chiwawa("Chiwawa");
    Cat persian("Persian");
    chiwawa.makeSound();
    persian.makeSound();

    std::cout << "\n" << std::endl;
    //create some specific objects by copying
    Cat persian2(persian);
    persian.makeSound();

    std::cout << "\n" << std::endl;
    //create some specific objects by assigning other to them
    Dog chiwawa3;
    chiwawa3 = chiwawa;
    chiwawa3.makeSound();
    */

    const Animal    *meta = new Animal();
    const Animal    *j = new Dog();
    const Animal    *i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
    
    return (0);
}