/**
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#include "test_generator.hpp"


void generate_fenwick_test(const long long int size)
{
    srand (time(NULL));

    std::cout << size << " " << size << std::endl;

    for (long long int i = 0; i < size; ++i)
    {
        long long int ix = rand() % size;
        if ((rand() % 2) == 0)
        {
            long long int delta = (rand() % 2000000000) - 1000000000;
            std::cout << "+ " << ix << " " << delta << std::endl;
        }
        else
        {
            std::cout << "? " << ix << std::endl;
        }
    }
}

void generate_union_find_test(const long long int size)
{
    srand (time(NULL));

    std::cout << size << " " << size << std::endl;

    for (long long int i = 0; i < size; ++i)
    {
        long long int a = (rand() % size);
        long long int b = (rand() % size);
        if ((rand() % 2) == 0)
            std::cout << "= " << a << " " << b << std::endl;
        else
            std::cout << "? " << a << " " << b << std::endl;
    }
}
