/**
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#include "algorithms.hpp"


const std::vector<int> cover(const Interval& interval,
                             std::vector<Interval>& parts)
{
    int min = 0;
    int max = parts.size();
    long double left_coord = interval._left;
    std::vector<Interval> original_parts = parts;
    std::vector<int> indices;

    std::sort(parts.begin(), parts.end());

    // Special case for point interval
    if (interval._left == interval._right)
    {
        for (unsigned int i = 0; i < parts.size(); ++i)
        {
            Interval part = parts[i];
            if ((interval._left >= part._left) && (interval._right <= part._right))
            {
                indices.push_back(part._index);
                break;
            }
        }
        return indices;
    }

    while ((left_coord < interval._right) && (min < max))
    {
        Interval part = parts[min];
        Interval best_part = part;

        while ((part._left <= left_coord) && (min < max - 1))
        {
            ++min;
            Interval next = parts[min];
            if ((next._right > best_part._right) && (next._left <= left_coord))
                best_part = next;
            part = next;
        }

        if ((best_part._left > left_coord) || best_part._right <= left_coord)
            break;

        indices.push_back(best_part._index);
        left_coord = best_part._right;
    }

    // Since the last part is always added, verify that it is legit
    if ((max > 0) && (indices.size() > 0))
    {
        Interval last = original_parts[indices.back()];
        if ((last._left > left_coord) || (last._right < interval._right))
            indices.clear();
    }

    return indices;
}

std::vector<long int> knapsack(const long int capacity,
                               const int_pairs& value_weight)
{
    long int num_objects = value_weight.size();
    std::vector<long int> indices;
    int_matrix max_val(num_objects + 1, std::vector<long int>(capacity + 1, 0));

    for (long int i = 1; i < num_objects + 1; ++i)
    {
        std::pair<long int, long int> item = value_weight[i - 1];
        long int value = item.first;
        long int weight = item.second;
        for (long int j = 0; j < capacity + 1; ++j)
        {
            if (weight <= j)
            {
                max_val[i][j] = std::max(max_val[i - 1][j],
                                         max_val[i - 1][j - weight] + value);
            }
            else
                max_val[i][j] = max_val[i - 1][j];
        }
    }

    long int j = capacity;
    for (long int i = num_objects; i >= 1; --i)
    {
        if (max_val[i][j] != max_val[i - 1][j])
        {
            indices.push_back(i - 1);
            j -= value_weight[i - 1].second;
        }
    }

    return indices;
}

const std::vector<long int> lis(const std::vector<long int>& integers)
{
    std::vector<long int> indices = {0};
    std::vector<long int> min_end = {integers.front()};
    std::vector<long int> parents(integers.size());
    parents[0] = MAX_LINT;

    for (long int i = 1; i < (long int) integers.size(); ++i)
    {
        long int selected = integers[i];

        if (selected > min_end.back())
        {
            min_end.push_back(selected);
            parents[i] = indices.back();
            indices.push_back(i);
        }
        else
        {
            // Find first element not less than selected
            auto it = std::lower_bound(min_end.begin(), min_end.end(), selected);
            long int ix = it - min_end.begin();
            min_end[ix] = selected;
            indices[ix] = i;
            if (ix > 0)
                parents[i] = indices[ix - 1];
            else
                parents[i] = MAX_LINT;
        }
    }

    // Backtrack to find the corresponding indices
    std::vector<long int> result;
    long int parent = indices.back();
    while (parent != MAX_LINT)
    {
        result.insert(result.begin(), parent);
        parent = parents[parent];
    }

    return result;
}

// ======== Union-Find ========

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
