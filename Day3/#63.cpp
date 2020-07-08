"https://leetcode.com/problems/unique-paths-ii/"
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int dp[100][100]={0};
        int n=(int)(grid.size());
        int m=(int)(grid[0].size());
        dp[0][0]=(grid[0][0]==0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i+j==0)continue;
                if(grid[i][j])continue; // grid[i][j] is obstacle
                if(i>0)dp[i][j]+=dp[i-1][j];
                if(j>0)dp[i][j]+=dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};