/**
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#pragma once


/**
 * Represents a Fenwick/BIT.
 */
struct fenwick
{
    private:
        const long long int _size;
        long long int* _tree;

    public:
        /**
         * @param input_size: The size of the tree.
         */
        fenwick(const long long int);

        ~fenwick();

        /**
         * Read the index sum.
         *
         * @param idx: Index for the end of the prefix to sum.
         * @return: The prefix sum.
         */
        long long int read(long long int);

        /**
         * Update the tree with the given value.
         *
         * @param idx: The index of node to change.
         * @param val: The amount to change.
         */
        void update(long long int, const long long int);
};
