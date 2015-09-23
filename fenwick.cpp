#include "fenwick.hpp"


fenwick::fenwick(const long int input_size) :
    _size(input_size)
{
    _tree = new long int[_size];
}

fenwick::~fenwick()
{
    delete [] _tree;
}

long int fenwick::read(long int idx)
{
    long int sum = 0;
    while (idx > 0)
    {
        sum += _tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void fenwick::update(long int idx , const long int val)
{
    while (idx <= _size)
    {
        _tree[idx] += val;
        idx += (idx & -idx);
    }
}
