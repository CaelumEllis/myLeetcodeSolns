#include <string>
#include <algorithm>
#include "same_letters.hpp"
#include "vector"
#include "iostream"

// given two strings, return true if and only if they contain 
// exactly the same letters including repetition.
bool sameLetters( const std::string& firstString, const std::string& secondString) {
  std::vector<char> firstVec(firstString.begin(), firstString.end());
  std::vector<char> secondVec(secondString.begin(), secondString.end());

  size_t firstSize = firstVec.size();
  size_t secondSize = secondVec.size();

  if(firstSize != secondSize){
    return false;    
  }
  
  std::sort(firstVec.begin(), firstVec.end());
  std::sort(secondVec.begin(), secondVec.end());

  for(size_t i {}; i < firstSize; i++){
    if(firstVec[i] != secondVec[i]){
      return false;
    }
  }
  return true;
}
