"https://leetcode.com/problems/search-in-rotated-sorted-array/"
//https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14425/Concise-O(log-N)-Binary-search-solution

class Solution {
public:
    int search(vector<int>& a, int target) {
        int n=(int)(a.size());
        int rot=0, low=0,up=n-1;
        if(n==0)return -1;
        if(n==1)return (a[0]==target?0:-1);
        while(up>low){
            int mid=(up+low)/2;
            if(a[mid]>a[up])low=mid+1;
            else up=mid;
        }
        rot=low;
        int l=0,u=n-1;
        while(l<=u){ //ye khudse :D 
            int mid=(l+u)/2;
            if(a[(mid+rot)%n] == target){
                return (mid+rot)%n;
            }else if(a[(mid+rot)%n] < target){
                l=mid+1;
            }else{
                u=mid-1;
            }
        }
        return -1;
    }
};

//another solution

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=(int)nums.size();
        if(n==0) return -1;
        else if(n==1){
            if(nums[0]==target)
                return 0;
            else
                return -1;
        }
        int low=0;int high=n-1;
        int pivot;
        while(low<high)
        {
            int mid=(low+high)/2;
            if(mid<=high&&nums[mid]>nums[high]){
                low=mid+1;
                pivot=mid;//at which array rotation ends
            }
            else high=mid;
        }
        low=0;high=n-1;
        pivot=(pivot+1)%n;
        if(nums[pivot]<=target&&nums[high]>=target)
            low=pivot;
        else
            high=pivot-1;
            
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return -1; 
    }
};