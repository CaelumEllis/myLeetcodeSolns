#include <algorithm>
#include <string>
#include <unordered_map>
#include "unique.hpp"

std::size_t firstUniqueChar(const std::string& inputString) {
  // write your solution here
  std::unordered_map<char, int> cnt;

  for(std::size_t i = 0; i < inputString.size(); i++ ){
    char num = inputString[i];
    cnt[num]++;
  }

  for(std::size_t i = 0; i < inputString.size(); i++ ){
    if(cnt[inputString[i]] == 1){
      return i;
    }
  }
  return inputString.size();
}
