"https://leetcode.com/problems/xor-queries-of-a-subarray/submissions/"
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        long long pre[30005]={0};
        int n=(int)(arr.size());
        for(int i=0;i<n;i++)pre[i+1]=pre[i]^arr[i]; // prefix of xor upto i in pre[i+1]
        vector<int> ans;
        for(auto q:queries){
            int l=q[0]+1,r=q[1]+1;
            ans.push_back(pre[r]^pre[l-1]); // xor of a^a=0
        }
        return ans;
    }
};