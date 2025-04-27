#include <vector>
#include <queue>
#include <algorithm>
#include "playdough.hpp"

int lastBallWeight(const std::vector<int>& weights) {
  std::priority_queue<int> orderedWeights(weights.begin(), weights.end());

  while(orderedWeights.size() > 1){
    int topOrdered = orderedWeights.top();
    orderedWeights.pop();

    int secondTopOrdered = orderedWeights.top();
    orderedWeights.pop();

    if(topOrdered != secondTopOrdered){
      orderedWeights.push(topOrdered - secondTopOrdered);
    }
  }

  if(orderedWeights.size() != 0){
    return orderedWeights.top();
  }
  return 0;
}
