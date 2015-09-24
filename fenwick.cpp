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

long long int fenwick::read(long long int idx)
{
    long long int sum = 0;
    while (idx > 0)
    {
        sum += _tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void fenwick::update(long long int idx , const long long int val)
{
    while (idx <= _size)
    {
        _tree[idx] += val;
        idx += (idx & -idx);
    }
}
