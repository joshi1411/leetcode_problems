"https://leetcode.com/problems/powx-n/" 
class Solution {
public:
    double myPow(double x,long n) { // long n krna pda qs mai ! overflow horha 
      
        double ans=1;
        bool flip=false;//can be converted to unsigned to increase range
        if(n<0){
            flip=true;n=-n;
            cout<<n;
        }
        while(n){
            if(n&1)
                ans=ans*x;
            x=x*x;
            n/=2;
        }
        if(flip)ans=1/ans;
        return ans;
    }
};
//same with unsigned
class Solution {
public:
    double myPow(double x, int n) {
        double res=1;
        bool flag=false;
        unsigned int m;
        if(n<0){
            m=-(unsigned int)n;
            flag=true;
        }
        if(!flag)
            m=n;
        while(m>0)
        {
            if(m%2!=0)
                res=res*x;
            m=m>>1;
            x=x*x;
        }
        if(flag){
            res=1/res;
        }
        return res;
        
    }
};