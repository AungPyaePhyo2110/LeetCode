// Given a string s, find the length of the longest substring without repeating characters.
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool includedArray[128];
       int longestLength = 0;
       int currentLength = 0;

        for(int i = 0 ; i < s.size() ; i++){
           memset(includedArray,false,128);
           includedArray[(s[i]-' ')] = true;
           currentLength = 1;
            for(int j = i+1 ; j < s.size() ; j++) {
                if(includedArray[(s[j]-' ')]){
                    break;
                }
                else{
                    currentLength++;
                    includedArray[(s[j]-' ')] = true;
                }

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


}