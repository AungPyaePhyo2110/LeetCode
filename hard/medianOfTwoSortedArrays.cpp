// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() == 0)
            return oneArrayMedian(nums2);
        if (nums2.size() == 0)
            return oneArrayMedian(nums1);

        int totalSize = nums1.size() + nums2.size();
        double result = 0;
        int medianSize = (totalSize + 1) / 2;
        int low1 = 0, low2 = 0;
        int hi1 = nums1.size() - 1, hi2 = nums2.size() - 1;
        int middle1 = 0, middle2 = 0;
        if (isEven(totalSize))
        {
            while (true)
            {
                middle1 = low1 + (hi1 - low1) / 2;
                middle2 = low2 + (hi2 - low2) / 2;
                if (middle1 + middle2 == medianSize - 2)
                {
                    result+= nums1[middle1] > nums2[middle2] ? nums1[middle1] : nums2[middle2];
                    result += nums1[middle1+1] < nums2[middle2+1] ? nums1[middle1+1] : nums2[middle2+1];
                    return result/2;
                }
                if (low1 <= hi1 && nums1[middle1] >= nums2[middle2])
                {
                    hi1 = middle1 ;
                }
                else if (low2 <= hi2 && nums2[middle2] > nums2[middle1])
                {
                    hi2 = middle2 ;
                }
            }
        }
        else
        {
            while (true)
            {
                middle1 = low1 + (hi1 - low1) / 2;
                middle2 = low2 + (hi2 - low2) / 2;
                if (middle1 + middle2 == medianSize - 2)
                {
                    return nums1[middle1] > nums2[middle2] ? nums1[middle1] : nums2[middle2];
                }
                if (low1 <= hi1 && nums1[middle1] >= nums2[middle2])
                {
                    hi1 = middle1 ;
                }
                else if (low2 <= hi2 && nums2[middle2] > nums2[middle1])
                {
                    hi2 = middle2;
                }
            }
        }
        return result;
    }

private:
    bool isEven(int number)
    {
        return number % 2 == 0;
    }
    double oneArrayMedian(vector<int> &nums)
    {
        if (isEven(nums.size()))
            return (double)(nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2;
        else
            return (double)nums[nums.size() / 2];
    }
};

int main()
{
    Solution solution;
    vector<int> nums1;
    vector<int> nums2;

    nums1 = {1, 3, 5, 7, 9};
    nums2 = {2, 4, 6, 8};
    assert(solution.findMedianSortedArrays(nums1, nums2) == 5);

    nums1 = { 1 , 3};
    nums2 = { 2 , 4};
    assert(solution.findMedianSortedArrays(nums1,nums2) == 2.5);

    nums1 = { 1 , 3};
    nums2 = { 2 };
    assert(solution.findMedianSortedArrays(nums1,nums2) == 2) ;


    nums1 = { 0 , 0 , 0 , 0 , 0};
    nums2 = { -1 , 0 , 0 , 0 , 0 , 0 , 1 };
    assert(solution.findMedianSortedArrays(nums1,nums2) == 0);

}

// naive solutin would be merging the two arrays
//