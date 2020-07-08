"https://leetcode.com/problems/longest-substring-without-repeating-characters/"
class Solution { // editorial has better solution
public:
    map<char,int> m;
    bool check(){
        bool ok=true;
        for(auto i:m)if(i.second>1)ok=false;
        return ok;
    }
    int lengthOfLongestSubstring(string s) { // Binary Search + sliding window
        int ans=1,l=1,n=(int)(s.size());
        int u=n;
        if(s.size()==0)return 0;
        while(u>=l){
            m.clear();
            int mid=(l+u)/2;
            bool ok=false;
            for(int i=0;i<mid;i++)
                m[s[i]]++;
            ok|=check();
            for(int i=mid;i<n;i++){
                m[s[i-mid]]--;
                m[s[i]]++;
                ok|=check();
            }
            if(ok){
                l=mid+1;
                ans=max(ans,mid);
            }else u=mid-1;
        }
        return ans;
    }
};