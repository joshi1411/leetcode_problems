"https://leetcode.com/problems/power-of-two/"
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n>0 && (n&(n-1))==0)return true; //if(n>0 && n&(n-1)==0) is wrong because && have higher priority than & ,always use parenthesis to avoid unnecessary headaches...ohkay
        else return false;
    }
};