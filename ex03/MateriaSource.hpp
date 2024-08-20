#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
    private:
        AMateria    *_storage[4];

    public:
        MateriaSource();
        MateriaSource(const MateriaSource &other);
        MateriaSource   &operator=(const MateriaSource &other);
        ~MateriaSource();
        void    learnMateria(AMateria *m);
        AMateria    *createMateria(std::string const &type);
};

#endif