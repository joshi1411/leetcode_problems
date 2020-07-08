"https://leetcode.com/problems/pascals-triangle-ii/"
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long int n=rowIndex; // you can change the name of rowIndex in function paramter too i.e getRow(int n) long required tha
            vector<int>row={1};
            for(long long int k=1;k<=n;k++){
                row.push_back(row.back()*(n+1-k)/k);//(binomial property) ohkay
            }
        return row;
        
    }
};
