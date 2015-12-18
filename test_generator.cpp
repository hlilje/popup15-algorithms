/*
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#include "test_generator.hpp"


void generate_fenwick_test(const long long int size)
{
    srand (time(NULL));

    std::cout << size << " " << size << std::endl;

    for (long long int i = 0; i < size; ++i)
    {
        long long int ix = rand() % size;
        if ((rand() % 2) == 0)
        {
            long long int delta = (rand() % 2000000000) - 1000000000;
            std::cout << "+ " << ix << " " << delta << std::endl;
        }
        else
        {
            std::cout << "? " << ix << std::endl;
        }
    }
}

void generate_shortest_path_test(const long nodes, const long edges,
                 const long requests)
{
    srand (time(NULL));

    std::cout << nodes << " " << edges << " " << requests << " "
          << 0 << std::endl;

    for (long i = 0; i < edges; ++i)
    {
        long long int a = (rand() % nodes);
        long long int b = (rand() % nodes);
        long long int w = (rand() % 1000);
        std::cout << a << " " << b << " " << w << std::endl;
    }

    for (long i = 0; i < requests; ++i)
    {
        long long int a = (rand() % nodes);
        std::cout << a << std::endl;
    }
    std::cout << "0 0 0 0" << std::endl;
}

void generate_union_find_test(const long long int size)
{
    srand (time(NULL));

    std::cout << size << " " << size << std::endl;

    for (long long int i = 0; i < size; ++i)
    {
        long long int a = (rand() % size);
        long long int b = (rand() % size);
        if ((rand() % 2) == 0)
            std::cout << "= " << a << " " << b << std::endl;
        else
            std::cout << "? " << a << " " << b << std::endl;
    }
}
void generate_bad_shortest_path_demo(const long long int size)
{
    //num_nodes, num_edges, num_queries, start_node
    long long int max_dist = size*2;
    std::cout << size << " " <<  size*(size-1) << " " << size << " " << 0 << std::endl;
    
    for (long long int i = 0; i < size; ++i){
        //edges 'backwards', weight doesn't matter
        for (long long int j = 0; j < i; ++j){
            std::cout << i << " " << j << " " << 1 << std::endl;
        }
        
        //special edge, making i+1 'free of charge'
        if (i+1<size){
            std::cout << i << " " << (i+1) << " " << 1 << std::endl;
        }
        
        //edges 'forwards', weight decreasing
        for (long long int j = i+2; j < size; ++j){
            std::cout << i << " " << j << " " << max_dist << std::endl;
        }
        max_dist -= 2;
    }
    for (long long int i = 0; i < size; ++i){
        std::cout << i << std::endl;
    }
    std::cout << "0 0 0 0" << std::endl;
}

