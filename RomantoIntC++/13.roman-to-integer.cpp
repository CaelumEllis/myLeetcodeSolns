/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        
        int length = s.length();
        std::array<char, 20> arr;
        std::array<char, 2> arr2;
        std::array<int, 2> arr3;
        int cnt = 0;
        std::copy(s.begin(), s.end(), arr.begin());

        for (int i = 0; i < length; i++)
        {
            arr2[0] = arr[i];
            if (i+1 >= length){
                arr2[1] = 0;
            } else { 
                arr2[1] = arr[i+1];}
            
            int x = 0;
            while(x < 2 ){
                if (arr2[x] == 'I'){
                    arr3[x] = 1;
                } else if (arr2[x] == 'V'){
                    arr3[x] = 5;
                } else if (arr2[x] == 'X'){
                    arr3[x] = 10;
                } else if (arr2[x] == 'L'){
                    arr3[x] = 50;
                } else if (arr2[x] == 'C'){
                    arr3[x] = 100;
                } else if (arr2[x] == 'D'){
                    arr3[x] = 500;
                } else if (arr2[x] == 'M'){
                    arr3[x] = 1000;
                } else if (arr2[x] == 0){
                    arr3[x] = 0;
                }
                x++;
            }
            if (arr3[0] < arr3[1] && arr3[1] != 0){
                cnt = cnt - arr3[0];
            } else {
                cnt = cnt + arr3[0];
            }
        }
       return cnt;
    }
};
// @lc code=end

