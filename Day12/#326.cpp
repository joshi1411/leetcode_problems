"https://leetcode.com/problems/power-of-three"

bool isPowerOfThree(int n) {
        double eps = 1e-3;
        if(n<=0)
            return false;
        double d=(log10(n)/log10(3))+eps;
        if((int)d%1<=2*eps)
            return true;
        else
            return false;
        
        
}