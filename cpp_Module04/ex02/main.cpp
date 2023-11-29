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
    Dog dog;
    Cat cat;
    //Animal animal;
    
    dog.makeSound();
    cat.makeSound();
    //animal.makeSound();

    return 0;
}