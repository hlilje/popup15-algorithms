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
