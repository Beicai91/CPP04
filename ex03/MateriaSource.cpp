#include "MateriaSource.hpp"

//constructors and destructor
MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        this->_storage[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    //deep copy!!
    for (int i = 0; i < 4; ++i)
        this->_storage[i] = (other._storage[i])->clone();
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
    {
        if (this->_storage[i])
        {
            delete this->_storage[i];
            this->_storage[i]= NULL;
        }
    }
    std::cout << "source tool deleted" << std::endl;
}

//operator
MateriaSource   &MateriaSource::operator=(const MateriaSource &other)
{
    if (this == &other)
        return (*this);
    //delete previously allocated memory before deep copying
    for (int i = 0; i < 4 && this->_storage[i]; ++i)
    {
        delete this->_storage[i];
        this->_storage[i] = NULL;
    }
    //deep copy
    for (int i = 0; i < 4; ++i)
        this->_storage[i] = (other._storage[i])->clone();
    return (*this);
}

//public member funcs
void    MateriaSource::learnMateria(AMateria *m)
{
    int i;

    i = 0;
    while (this->_storage[i])
        i++;
    if (i < 4)
        this->_storage[i] = m;
    else
    {
        std::cout << "Materia source storage is full" << std::endl;
        std::cout << "Clean this extra materia" << std::endl;
        delete m;
    }
}

AMateria    *MateriaSource::createMateria(std::string const &type)
{
    int i;

    i = 0;
    while (i < 4 && (this->_storage[i])->getType() != type)
        i++;
    if (i < 4)
        return ((this->_storage[i])->clone());
    else
    {
        std::cout << "Nothing found in the source storage to match the type you want to creat" << std::endl;
        return (0);
    }
}