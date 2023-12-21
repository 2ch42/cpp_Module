#include "Serializer.hpp"

int main()
{
    Data* test1 = new Data();
    test1->num = 10;
    test1->c = 'a';

    uintptr_t address1 = Serializer::serialize(test1);

    std::cout << "num of test1 : " << test1->num << ", c of test1 : " << test1->c << std::endl;
    std::cout << "test1 Address : " << address1 << std::endl;

    Data* test2 = Serializer::deserialize(address1);
    std::cout << "num of test2 : " << test2->num << ", c of test2 : " << test2->c << std::endl;

    uintptr_t address2 = Serializer::serialize(test2);
    std::cout << "test2 Address : " << address2 << std::endl;

    delete test1;

    return (0);
}