/**
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#pragma once


struct set
{
    set* parent;    // Parent pointer
    long int rank;  // Rank/height
    long int value; // Node value

    /**
     * @param value: The node value.
     */
    set(const long int);
};


/**
 * Find parent recursively using DFS.
 *
 * @param:  The set to start searching from.
 * @return: The found set.
 */
set* find(set*);

/**
 * Check if the given sets are connected.
 *
 * @param x: The first set to compare.
 * @param y: The second set to compate.
 * @return:  True if x and y are in the same set.
 */
bool same(set*, set*);

/**
 * Union sets by attaching the root of one to the root of the other.
 *
 * @param x: The first set to union.
 * @param y: The second set to union.
 */
void set_union(set*, set*);
