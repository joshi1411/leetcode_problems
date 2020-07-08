"https://leetcode.com/problems/best-time-to-buy-and-sell-stock/"
class Solution {
public:
    int maxProfit(vector<int>& a) {
        int ans=0,n=(int)(a.size());
        if(n-1>=0){
            int mxsell=a[n-1];
            for(int i=n-2;i>=0;i--){
                ans=max(ans,mxsell-a[i]); // maxsell is the max selling price which we can get if we buy on ith day (and sell on the day which gives max profit from i+1 to n )
                mxsell=max(mxsell,a[i]);//ohkie
            }
        }
        return ans;
    }
};