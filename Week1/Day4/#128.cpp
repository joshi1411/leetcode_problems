"https://leetcode.com/problems/longest-consecutive-sequence/" // not so hard
class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        set<int> s;
        for(auto i:a)s.insert(i);
        int ans=(a.size()>0),l=0,r=0;
        int last=*(s.begin());
        for(auto i:s){
            if(i==last)continue;
            if(i==last+1){
                r++;
                ans=max(ans,r-l+1);
            }else r=l=0;
            last=i;
        }
        return ans;
    }
};