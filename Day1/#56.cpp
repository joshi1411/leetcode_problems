"https://leetcode.com/problems/merge-intervals/"
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intr) {
        sort(intr.begin(),intr.end());
        vector<vector<int>> ans;
        if(intr.size()>0){
            int x=intr[0][0],y=intr[0][1];
            for(int i=1;i<(int)(intr.size());i++){
                if(intr[i][0]>=x && intr[i][1]<=y)continue;
                if(intr[i][0] <= y){
                    y=intr[i][1];
                }else{
                    ans.push_back({x,y});
                    x=intr[i][0];
                    y=intr[i][1];
                }
            }
              ans.push_back({x,y});
        }
        return ans;
    }
};
