#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    WrongAnimal  *meta = new WrongAnimal();
    WrongAnimal  *i = new WrongCat();
    WrongCat    *j = new WrongCat("persian");

    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    meta->makeSound();
    j->makeSound();

    delete meta;
    delete i;
    delete j;
    return (0);
}