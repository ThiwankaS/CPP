#include <iostream>

#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "test.hpp"

int main(void) {

    test("test case 01");
    TEST_NAME("Subject suggested test program");
    LINE_DATA;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* temp;

    temp = src->createMateria("ice");
    me->equip(temp);
    temp = src->createMateria("cure");
    me->equip(temp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);
    LINE_DATA;

    test("test case 02");
    TEST_NAME("Adding more materials to slot 02 and 03");
    LINE_DATA;
    temp = src->createMateria("ice");
    me->equip(temp);
    temp = src->createMateria("ice");
    me->equip(temp);

    test("test case 03");
    TEST_NAME("Using all materials on bob");
    LINE_DATA;
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);

    test("test case 04");
    TEST_NAME("Remove materials on slot 02");
    LINE_DATA;
    me->unequip(2);

    test("test case 05");
    TEST_NAME("Adding different material slot 02");
    LINE_DATA;
    temp = src->createMateria("cure");
    me->equip(temp);

    test("test case 06");
    TEST_NAME("Using all materials on bob");
    LINE_DATA;
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);

    delete bob;
    delete me;
    delete src;
    return (EXIT_SUCCESS);
}
