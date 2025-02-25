#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // code here
        int n=nums.size();
        vector< int> ans(n,1);
         int left=1;
        for(int i=0;i<n;i++){
            ans[i]=left;
            left=left*nums[i];
        }
         int right=1;
        for(int i=n-1;i>=0;i--){
            ans[i]=right*ans[i];
            right=right*nums[i];
        }
        return ans;
    }
};