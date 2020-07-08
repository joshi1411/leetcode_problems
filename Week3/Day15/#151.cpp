"https://leetcode.com/problems/reverse-words-in-a-string"

class Solution {
public:
//using two pointers
    string reverseWords(string s) {
        string res;
        int n=s.size();
        if(n==0||s.empty())
            return res;
        int i=n-1;
        while(i>=0)
        {
        if(s[i]==' ')
        {
            i--;
            continue;
        }
            int j=i-1;
            while(j>=0&&s[j]!=' ')
                j--;
            res.append(" ");
            res.append(s.substr(j+1,i-j));
            i=j-1;
        }   
        if(res.size()>0)
            return res.substr(1);
        return res;
    }

//other solution
    string reverseWords(string s) {
        s=s+"*";
        string temp="";
        int len=0;
        bool ok=false;
        for(int i=0;s[i]!='*';i++){
            if(s[i]==' '){
                if(temp!=""){
                    s=temp+" "+s;
                    i+=(int)(temp.size());
                    len+=(int)(temp.size())+1;
                    temp="";
                }
            }else{
                ok=true;
                temp=temp+s[i];
            }
        }
        if(temp!=""){
            s=temp+" "+s;
            len+=(int)(temp.size());
        }else{
            if(ok)len--;
        }
        return s.substr(0,len);
    }
};
