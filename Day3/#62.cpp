"https://leetcode.com/problems/unique-paths/" // can be done using combinatorics
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[100][100]={0};
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i+j==0)continue; // similar to (i==0 && j==0)
                if(j>0)dp[i][j]+=dp[i][j-1];
                if(i>0)dp[i][j]+=dp[i-1][j];
            }
        }
        return dp[n-1][m-1];
    }
};
