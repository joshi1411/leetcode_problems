" https://leetcode.com/problems/max-consecutive-ones/submissions/"
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int j=0;
        if(nums.size()==0||(nums.size()==1&&nums[0]==0))
            return 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                j++;
                ans=max(ans,j);
            }
            else{
              j=0;
            }
        }
        return ans;
    }
};