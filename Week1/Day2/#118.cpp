"https://leetcode.com/problems/pascals-triangle"
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> pas(n);
        if(n>0){
            pas[0].push_back(1);
            for(int i=1;i<n;i++){
                vector<int> temp(i+1);
                for(int j=0;j<i+1;j++){
                    if(j<i)temp[j]+=pas[i-1][j];
                    if(j-1>=0)temp[j]+=pas[i-1][j-1];
                }
                pas[i]=temp;
            }
        }
        return pas;
    }
};
//method2
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows==0)
            return ans;
        for(int n=0;n<numRows;n++){
            vector<int>row={1};
            for(int k=1;k<=n;k++){
                row.push_back(row.back()*(n+1-k)/k);
            }
            ans.push_back(row);
        }
        
        return ans;
    }
};