"https://leetcode.com/problems/excel-sheet-column-number/"
class Solution {
public:
    int titleToNumber(string s) {
        int ct=0;
        long long ans=0;
        for(auto i:s){
            ans=ans*26LL + (int)(i-'A')+1; // similar to calculating number in base 26 if 1 is A and Z is 26
        }
        return ans;
    }
};