// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> myMap;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            myMap[nums[i]] = i;
            
        }
        for(int i = 0; i < nums.size(); i++) {
            if(myMap.count(target-nums[i])>0 && i != myMap[target-nums[i]])
            {
                return vector<int> {i,myMap[target-nums[i]]};
            }
        }
        return vector<int>();
    }
};