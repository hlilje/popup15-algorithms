/* Authors: Isak Nilsson, Hampus Liljekvist*/

#include "kmp.hpp"

std::vector<long> make_pi(const std::string pattern){
    std::vector<long> pi(pattern.length(),0);
    for (size_t position = 1; position<pattern.length(); position++){
        long state = pi[position-1];
        while ((state > 0) && (pattern[state+1] != pattern[position])){
            state = pi[state];
        }
        if (pattern[state] == pattern[position]){
            pi[position] = state + 1;
        }
        else {
            pi[position] = 0;
        }
    }
    return pi;
}

std::vector<long> find(std::string pattern, std::string text, std::vector<long> pi){
    std::vector<long> indices;
    size_t q = 0;
    for (size_t i = 0; i<text.length(); i++){
        while ((q > 0) && (pattern[q] != text[i])){
            q = pi[q-1];
        }
        if (pattern[q] == text[i]){
            q = q+1;
        }
        if (q == (pattern.length() )){
            indices.push_back((i - (long)pattern.length() + 1));
            q = pi[q-1];
        }
    }
    return indices;

}
