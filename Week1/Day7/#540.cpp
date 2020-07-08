"https://leetcode.com/problems/single-element-in-a-sorted-array/"
class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n=(int)(a.size());
        if(n==1)return a[0];
        int low=0,up=n-1;
        int ans=-1;
        while(up>=low){
            int mid=(up+low)/2;
            int pos=-1;
            if(mid+1<n && a[mid]==a[mid+1]){
                pos=mid+1;
            }else if(mid-1>=0 && a[mid]==a[mid-1]){
                pos=mid;
            }

            if(pos==-1){
                ans=a[mid];
                break;
            }else if(pos%2){
                low=mid+1;
            }
            else{
                up=mid-1;
            }
        }
        return ans;
    }
};
//another soln(help and hint from gfg method)
//All elements before the required have the first occurrence at even index (0, 2, ..)
//and next occurrence at odd index (1, 3, …). And all elements after the required
//elements have the first occurrence at odd index and next occurrence at even index.
// yhi to maine v kia h ! see, agr 2 consecutive same element hai koi to usme 2nd wala occurance odd index pe hoga to avi tk nhi aya single element to low=mid+1 vice versa

class Solution {
public:
   int singleNonDuplicate(vector<int>& nums) {
        int low=0;
        int high=(int)nums.size()-1;
         while(low<=high)
         {
              int mid=(low+high)/2;
              if(low==high)
                  return nums[low];
              if(mid%2==0){
                  if(nums[mid]==nums[mid+1]){
                    low=mid+2;
                  }
                  else
                  {
                    high=mid;
                  }
             }
             else{
                  if(nums[mid]==nums[mid-1]){
                    low=mid+1;
                  }
                  else
                      high=mid-1;
						 }
        }
     return 0; 
    }
};

//better implementation
class Solution {
public:
   int singleNonDuplicate(vector<int>& nums) {
        int low=0;
        int high=(int)nums.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            mid-=(mid%2);
            if(low==high) return nums[low];
            if(nums[mid]==nums[mid+1]) low=mid+2;
            else high=mid;
        }
        return 0; 
   }
};