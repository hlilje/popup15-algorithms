/*
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#pragma once


/*
 * Represents a Fenwick/BIT.
 */
struct fenwick
{
    private:
        const long long int _size; // Size of tree
        long long int* _tree;      // Tree container

    public:
        /*
         * @param input_size: The size of the tree.
         */
        fenwick(const long long int);

        ~fenwick();

        /*
         * Get the tree sum up to end (exclusive).
         *
         * @param end: Index for the end of the prefix to sum.
         * @return:    The prefix sum.
         */
        long long int sum(long long int);

        /*
         * Increment the tree at the given position with the given value.
         *
         * @param i:     The index of node to change.
         * @param delta: The amount to change.
         */
        void add(long long int, const long long int);
};
