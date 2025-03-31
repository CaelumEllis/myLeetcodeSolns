#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int numberOfDistinctElements(const std::vector<int>& vec) {
  if (vec.size() == 0) {
    return 0;
  }

  std::vector copyVec = vec;
  
  std::sort(copyVec.begin(), copyVec.end());
  //unique sorts unique elements to the front, then pushes duplicates to the end and 
  //returns an iterator one pas the last unique element
  auto unique_nums = std::unique(copyVec.begin(), copyVec.end());
  //unlike i originally thought, unique returns an iterator as if you counted until out of unique elements,
  //thats why i must compare it to copyVec to return lengthm it is essentially copyVec.end(), 
  //if copyVec had all non unique elements removed
  return std::distance(copyVec.begin(), unique_nums);
}
