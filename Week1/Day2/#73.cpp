
"https://leetcode.com/problems/set-matrix-zeroes/solution/" //(fails when 1e9 is in array)
class Solution {
public:
    const int inf =1e9;
    void setZeroes(vector<vector<int>>& a) {
        int m=(int)(a[0].size());
        int n=(int)(a.size());
        for(int i=0;i<n;i++){
            bool zeros=false;
            for(int j=0;j<m;j++){
                if(a[i][j]==0)zeros=true;
            }
            if(zeros){
                for(int j=0;j<m;j++)
                  
                    if(a[i][j])
                        a[i][j]=inf;
            }
        }
        for(int j=0;j<m;j++){
            bool zeros=false;
            for(int i=0;i<n;i++){
                if(a[i][j]==0)zeros=true;
            }
            if(zeros){
                for(int i=0;i<n;i++)
                    if(a[i][j])
                        a[i][j]=inf;
            }
        }
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(a[i][j]==inf)a[i][j]=0;
    }
};
