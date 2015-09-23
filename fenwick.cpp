#include "fenwick.hpp"

struct fenwick{
private:
  long int _size;
  long int* _tree;
public:
  fenwick(long int input_size):_size(input_size) {
    _tree = new long int[_size];
  }
  ~fenwick(){
    delete [] _tree;
  }
  
  long int read(long int idx){
    long int sum = 0;
    while (idx > 0){
      sum += _tree[idx];
      idx -= (idx & -idx);
    }
    return sum;
  }

  void update(long int idx , long int val){
    while (idx <= _size){
      _tree[idx] += val;
      idx += (idx & -idx);
    }
  } 
};
