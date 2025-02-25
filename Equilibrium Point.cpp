#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
      int total_sum=0,left_sum=0;
        for(int i=0;i<arr.size();i++) total_sum+=arr[i];
        for(int i=0;i<arr.size();i++){
            int right_sum=total_sum-left_sum-arr[i];
            if(left_sum==right_sum) return i;
            left_sum+=arr[i];
        }
        return -1;
    }
};