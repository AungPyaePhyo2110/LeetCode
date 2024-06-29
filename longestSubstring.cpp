// Given a string s, find the length of the longest substring without repeating characters.
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lastSeenIndex[128];
        memset(lastSeenIndex,-1,sizeof(lastSeenIndex));
        int left = 0 ;
        int right = 0;
        int longestLength = 0;
        int currentLength = 0;
        for(right = 0 ; right < s.size() ; right++)
        {
            if(lastSeenIndex[s[right]] == -1){
                lastSeenIndex[s[right]] = right;
                currentLength++;
            }
            else{
                left = left > lastSeenIndex[s[right]] + 1 ? left : lastSeenIndex[s[right]] + 1;
                lastSeenIndex[s[right]] = right;
                currentLength = right - left + 1;
            }

            if(currentLength > longestLength)
                longestLength = currentLength;
        }

        return longestLength;
    }
};

int main() {
    Solution solution;
    assert( solution.lengthOfLongestSubstring(" ") == 1);
    assert( solution.lengthOfLongestSubstring("bbbbb") == 1);
    assert( solution.lengthOfLongestSubstring("kwwkew") == 3);
    assert(solution.lengthOfLongestSubstring("tmmzuxt") == 5);


}