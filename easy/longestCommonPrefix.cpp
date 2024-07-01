#include <vector>

using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        sort(strs.begin(),strs.end());
        string str1 = strs[0];
        string str2 = strs[strs.size()-1];
        int j = str1.size() < str2.size() ? str1.size() : str2.size();
        for(int i =0 ; i < j ; i++){
            if(str1[i]!=str2[i])
                break;
            result += str1[i];
        }

        return result;
    }
};