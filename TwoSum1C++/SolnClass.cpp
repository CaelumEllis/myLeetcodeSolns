#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    size_t n = nums.size();
    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                return {static_cast<int>(i), static_cast<int>(j)};
            }
        }
    }
       return {}; 
    }
};
