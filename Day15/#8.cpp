"https://leetcode.com/problems/string-to-integer-atoi/"
class Solution {
public:
    int myAtoi(string s) {
        int ans=0,n=(int)(s.size());
        int sign=1;bool ok=false;
        for(int i=0;i<n;i++){
            if((s[i]=='+' || s[i]=='-')){
                if(ok)break;
                if(s[i]=='+')sign=1;
                else sign=-1;
                ok=true;
                continue;
            }
            if(s[i]<='9' && s[i]>='0'){
                while(i<n && (s[i]<='9' && s[i]>='0')){
                    if((double)(INT_MAX - (int)(s[i]-'0'))/(double)(10)<ans){
                        ans=INT_MAX;
                        break;
                    }
                    if((double)(INT_MIN + (int)(s[i]-'0'))/(double)(10)>ans){
                        ans=INT_MIN;
                        break;
                    }
                    ans=ans*10+(sign)*(int)(s[i]-'0');
                    i++;
                }
                break;
            }
            if(ok)break;
            if(s[i]!=' ')break;
        }
        cout<<ans;
        return ans;
    }
};