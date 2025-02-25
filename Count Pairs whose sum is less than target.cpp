#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        sort(arr.begin(),arr.end());
        int left=0,right=arr.size()-1;
        int count=0;
        while(left<right){
            int sum=arr[left]+arr[right];
            if(sum<target){
                count+=(right-left);
                left++;
            }else{
                right--;
            }
        }
        return count;
    }
};