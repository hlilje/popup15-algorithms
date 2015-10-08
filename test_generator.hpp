/*
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#pragma once

#include <iostream>


/*
 * Generate a test case for the Fenwick Kattis problem.
 * The test will be printed to stdout.
 *
 * @param size: The size of the test case.
 */
void generate_fenwick_test(const long long int);

/*
 * Generate a test case for the Union-Find Kattis problem.
 * The test will be printed to stdout.
 *
 * @param size: The size of the test case.
 */
void generate_union_find_test(const long long int);

/*
 * Generate a test case for integer non-negative shortest
 * path Dijkstra.
 *
 * @param nodes: Number of nodes in the graph.
 * @param edges: Number of edges in the graph.
 * @param requests: Number of requested distances.
 */
void generate_shortest_path_test(const long, const long, const long);
