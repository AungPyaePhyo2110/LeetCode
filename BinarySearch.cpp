// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int hi = nums.size() -1 ;
        int middle = 0;
        while(low <= hi)
        {
            middle =  low + ( hi - low ) / 2;
            if(nums[middle] == target)
                return middle;
            else if (target < nums[middle])
                hi = middle - 1; 
            else
                low = middle + 1;
        }
        return low;
    }
};