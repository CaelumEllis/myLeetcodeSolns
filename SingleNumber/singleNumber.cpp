#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "single_number.hpp"

int singleNumber(const std::vector<int>& vec) {
  std::vector<int> newVec = vec;
  std::sort(newVec.begin(), newVec.end());

  size_t l1 = newVec.size();
  if(l1 < 2){
    return newVec[0];
  }

  for(size_t i = 0; i < l1; ++i){
    if(newVec[i]!= newVec[i+1] && newVec[i+1] != newVec[i+2]){
      return newVec[i+1];
    }
  }

  return l1;
}
