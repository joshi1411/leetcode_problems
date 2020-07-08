"https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/"
class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=(int)(a.size());
        int ans=0;
        if(n>0){
            int x=a[0],y=-1;
            for(int i=0;i<n;i++){
                if(a[i]>x){
                    ans+=a[i]-x;
                    x=a[i];
                }else x=min(x,a[i]);
            }
        }
        return ans;
    }
};
