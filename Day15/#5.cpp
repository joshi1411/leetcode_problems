"https://leetcode.com/problems/longest-palindromic-substring/submissions/"
class Solution {
public:
    string longestPalindrome(string s) {
        int mx=0,l=-1,r=-1,n=(int)(s.size());
        for(int i=0;i<(int)(s.size());i++){
            // assuming s[i] as center of palindrome
            // if even palindrome 
            int x=i-1,y=i;
            while(x>=0 && y<n && s[x]==s[y]){
                if(y-x+1>mx){
                    mx=y-x+1;
                    l=x,r=y;
                }
                x--,y++;
            }
            //odd length palindrome
            int z=1; // half length of palindrome
            if(mx==0){
                mx=1;
                l=i,r=i;
            }
            while(i-z>=0 && i+z<n && s[i-z]==s[i+z]){
                if(i+z-(i-z)+1>mx){
                    l=i-z,r=i+z;
                    mx=r-l+1;
                }
                z++;
            }
        }
        if(mx==0)return "";
        else return s.substr(l,r-l+1);
    }
};

//using Manacher's algorithm (overkill)
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();int start=0;
        if(n==0)
            return s;
        bool table[n][n];
        memset(table, 0, sizeof(table)); 
        int maxlength=1;
        for(int i=0;i<n;i++)
        {
            table[i][i]=true;
        }
        for(int i=0;i<n-1;i++)//check substrings of length2
        {
            if(s[i]==s[i+1]){
                table[i][i+1]=true;
                start=i;
                maxlength=2;
            }
        }
        for(int k=3;k<=n;k++)//size of substring possible
        {
            for(int i=0;i<(n-k+1);i++)//start index
            {
                int j=(i+k-1);//end index
                if((table[i+1][j-1])&&s[i]==s[j])
                {
                    table[i][j]=true;
                    if(k>maxlength)
                    {
                        start=i;
                        maxlength=k;
                    }
                }
            }
        }
        return(s.substr(start,maxlength));    
    }
};