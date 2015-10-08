/**
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#include "union_find.hpp"


set::set(const long int value) :
    // Recursion base case
    parent(this), rank(0), value(value) { }


set* find(set* x)
{
    // Flatten tree while searching
    if (x->parent != x)
        x->parent = find(x->parent);
    return x->parent;
}

bool same(set* x, set* y)
{
    return find(x) == find(y);
}

void set_union(set* x, set* y)
{
    // Ignore if they are in the same component
    set* x_root = find(x);
    set* y_root = find(y);
    if (x_root == y_root) return;

    // x and y not already in same set => merge.
    // Since depth affects running time, merge the tree with smaller depth
    // to the one with higher depth.
    if (x_root->rank < y_root->rank)
        x_root->parent = y_root;
    else if (x_root->rank > y_root->rank)
        y_root->parent = x_root;
    else
    {
        y_root->parent = x_root;
        ++(x_root->rank);
    }
}
