#include <algorithm>
#include <vector>
#include "second_largest.hpp"
#include <iostream>

// returns the second largest number in a vector of integers
// under the promise the vector has at least two elements
int secondLargest(const std::vector<int>& vec) {

  size_t n = vec.size();
 
  size_t cnt = 0;
  int cnt2 = 0;
  auto maxInt = std::max_element(vec.begin(), vec.end());
  int scndLrgstInt = 0;
  while(cnt < n){
    if(vec[cnt] > scndLrgstInt && vec[cnt] != *maxInt){
      scndLrgstInt = vec[cnt];
    }
    if(vec[cnt] == *maxInt){
      cnt2++;
    }
    cnt++;
  }
  if(cnt2 > 1){
    scndLrgstInt = *maxInt;
  }
  return scndLrgstInt;
}
