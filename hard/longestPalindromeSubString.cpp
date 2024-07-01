#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

        vector< vector<bool> > table ( s.size() , vector<bool>(s.size(),false));
        int startIndex = 0;
        int longestLength = 0;
        //one character is a palindrome


        // check one character ,2 characters .... n character
        // i for start , j for end
        for(int subStringSize = 0 ;  subStringSize < s.size() ; subStringSize++){
            for(int i = 0  , j = subStringSize ; j < s.size() ; i++ , j++){
                if(checkIsPalindrome(table,s,i,j)){
                    if(j - i + 1 > longestLength)
                        startIndex = i;
                        longestLength = j - i + 1;
                }
            }
        }


        return s.substr(startIndex,longestLength);


    }
private:
    bool checkIsPalindrome(vector<vector<bool> > & table , const string & s , int start , int end){
        // for one character
        if(start == end)
            return table[start][end] = true;

        if(s[start] != s[end])
            return table[start][end] = false;
        else if(end-start ==1)
            return table[start][end] = true;
        else if(table[start+1][end-1])
            return table[start][end] = true;
        else
            return table[start][end] = false;
        


    }
};


int main(){
    Solution Solution;
    assert(Solution.longestPalindrome("abbada") == "abba");
}