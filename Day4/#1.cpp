"https://leetcode.com/problems/two-sum/"
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m; // value,index
        vector<int> ans;
        for(int i=0;i<(int)(nums.size());i++){
            if(m.count(target-nums[i])){
                ans.push_back(m[target-nums[i]]);
                ans.push_back(i);
                break; 
            }
            m[nums[i]]=i;
        }
        return ans;
    }
};