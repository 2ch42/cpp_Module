#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

/*
void    check_leak(void)
{
    system("leaks test");
}
*/

int main()
{
    //atexit(check_leak);
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout << "\n----------------\n" << std::endl;

    const WrongAnimal* test1 = new WrongAnimal();
    const WrongAnimal* test2 = new WrongCat();

    std::cout << test1->getType() << " " << std::endl;
    std::cout << test2->getType() << " " << std::endl;
    test1->makeSound();
    test2->makeSound();

    delete meta;
    delete j;
    delete i;
    delete test1;
    delete test2;
    return 0;
}