#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

/*
void    check_leak(void)
{
    system("leaks test");
}
*/

int main() // test1
{
    //atexit(check_leak);
    Dog dog;
    Cat cat;
    
    dog.makeSound();
    cat.makeSound();

    return 0;
}

/*
int main() // test2 for pure virtual function
{
    atexit(check_leak);
    Animal animal;

    animal.makeSound();
    return (0);
}
*/