#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, std::size_t> partners {};
    
        for(int i = 0; i < nums.size(); i++ ){
            int value = nums[i];
            int matchingVal = target - value;
    
            if(partners.contains(matchingVal)){
                int j = partners[matchingVal];
                return{i, j};
            }
            else {
                partners[value] = i;
            }
        } 
        return {0,0};
    }
};
