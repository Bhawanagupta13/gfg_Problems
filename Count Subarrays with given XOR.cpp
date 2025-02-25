#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
   int subarrayXor(vector<int> a, int k) {
        // code here
        int xr=0;
        map<int,int>mpp;
        mpp[xr]++;
        int count=0;
        for(int i=0;i<a.size();i++){
            xr=xr ^ a[i];
            int x=xr ^ k;
            count+=mpp[x];
            mpp[xr]++;
        }
        return count;
    }
};
