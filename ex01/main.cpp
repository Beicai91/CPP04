#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
    Animal  *animals[10];

    for (int i = 0; i < 5; ++i)
        animals[i] = new Dog();
    for (int i = 5; i < 10; ++i)
        animals[i] = new Cat();
    for (int i = 0; i < 10; ++i)
        delete animals[i];

    std::cout << "\nSome other tests to prove deep copy\n" << std::endl;
    Dog *chiwawa = new Dog("chiwawa");
    Dog chiwawa2(*chiwawa);
    delete chiwawa;
    //chiwawa's brain memory is deleted but it won't affect chiwawa2's brain since they don't share the same brain memory
    chiwawa2.printIdeas();

    Cat persian("persian");
    Cat persian2(persian);
    std::cout << "persian's brain heap address " << persian.getBrain() << std::endl;
    std::cout << "persian2's brain heap address " << persian2.getBrain() << std::endl;
    return (0);
}