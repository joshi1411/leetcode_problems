"https://leetcode.com/problems/counting-bits/" //check https://oeis.org/A000120 formula section	
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1,0);
        for(int i=1;i<=num;i++){
            dp[i]=dp[i/2]+(i&1); // shorcut to void if-else 
        }
        return dp;
    }
};
//count set bits in an integer
while (n) { 
            n &= (n - 1); 
            count++; 
        } 
        return count; 

// from discussion channel
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};