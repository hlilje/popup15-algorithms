/*
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#include "knapsack.hpp"

typedef std::vector<std::vector<long int>> int_matrix;
typedef std::vector<std::pair<long int, long int>> int_pairs;


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
