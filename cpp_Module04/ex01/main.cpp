#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void    check_leak(void)
{
    system("leaks test");
}

int main()
{
    atexit(check_leak);
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;
    
    std::cout << "\n------Given Test------\n" << std::endl;

    Animal  *(animal_list[10]);
    for(int i = 0; i < 5; i++)
    {
        animal_list[i] = new Dog();
        animal_list[i + 5] = new Cat();
    }

    for(int i = 0; i < 10; i++)
    {
        delete animal_list[i];
    }
    
    return 0;
}