"https://leetcode.com/problems/subarray-sum-equals-k/"
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=(int)(nums.size());
        int pre[20005]={0};
        for(int i=0;i<n;i++)pre[i+1]=pre[i]+nums[i];
        map<int,int> m1;
        long long ans=0;
        for(int i=0;i<=n;i++){
            if(m1.count(pre[i]-k)){
                ans+=m1[pre[i]-k];
            }
            m1[pre[i]]++;
        }
        return ans;
    }
};