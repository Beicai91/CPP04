#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main(void)
{
    IMateriaSource  *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter  *me = new Character("me");

    AMateria    *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter  *bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    
    std::cout << "---unequip materias: unequip doesn't mean freeing materia users should manage memory leaks---" << std::endl;
    //since ICharacter doesn't have getInventoryMateria(), we need to cast me to Character type
    Character   *concrete_me = dynamic_cast<Character *>(me);
    AMateria    *tmp2 = concrete_me->getInventoryMateria(1);
    me->unequip(1);
    if (tmp2)
    {
        delete tmp2;
        tmp2 = NULL;
    }
    //unequip an empty slot
    tmp2 = concrete_me->getInventoryMateria(2);
    me->unequip(2);
    if (tmp2)
        delete tmp2;

    std::cout << "\n" << std::endl;
    std::cout << "---use an empty slot---" << std::endl;
    me->use(2, *bob);
    
    std::cout << "\n" << std::endl;
    std::cout << "---store materias in src more than its capacity---" << std::endl;
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());

    std::cout << "\n" << std::endl;
    std::cout << "---create a materia of an unkonwn type---" << std::endl;
    AMateria    *unknown = src->createMateria("fire");
    if (unknown == 0)
        std::cout << "No new materia is not created" << std::endl;

    std::cout << "\n" << std::endl;
    std::cout << "---create one more than what `me` can carries: memory leaks is handled by Character's equip function---" << std::endl;
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("ice"));
    std::cout << "`me`'s inventory is full at this point. Try to carry another one...?" << std::endl;
    me->equip(src->createMateria("cure"));


    std::cout << "\n" << std::endl;
    std::cout << "---create new character jerry on stack and then tom by copying jerry: prove deep copy---" << std::endl;
    Character  jerry("jerry");
    jerry.equip(src->createMateria("ice"));
    Character   jerry_copy(jerry);
    std::cout << "jerry's inventory: first slot's content address " << &((jerry.getInventoryMateria(0))->getType()) << std::endl;
    std::cout << "tom's inventory: first slot's content address " << &((jerry_copy.getInventoryMateria(0))->getType()) << std::endl;
    

    delete bob;
    delete me;
    delete src;
    return (0);
}