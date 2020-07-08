"https://leetcode.com/problems/integer-to-roman/"
class Solution {
public:
    string intToRoman(int num) {
        int val[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string res[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string ans="";
        int i=0;            
        while(num>0){
            while(num>=val[i]){
                num-=val[i];
                ans=ans+res[i];
            }
            i++;
        }
        return ans;
    }
};