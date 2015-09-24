/**
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#include "fenwick.hpp"


fenwick::fenwick(const long long int input_size) :
    _size(input_size)
{
    _tree = new long long int[_size];
}

fenwick::~fenwick()
{
    delete [] _tree;
}

long long int fenwick::sum(long long int end)
{
    long long int acc_sum = 0;
    while (end > 0)
    {
        acc_sum += _tree[end];
        end -= (end & -end);
    }
    return acc_sum;
}

void fenwick::add(long long int i , const long long int delta)
{
    while (i <= _size)
    {
        _tree[i] += delta;
        i += (i & -i);
    }
}
