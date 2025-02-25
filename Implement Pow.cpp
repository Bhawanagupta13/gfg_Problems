#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {  
  public:
    double power(double b, int e) {
        // code here
        if(e==0) return 1;
        if(e<=0) return 1/power(b,-e);
        
        double tempans =power(b,e/2);
        if(e%2==0){
            return tempans*tempans;
        }
        else{
            return tempans*tempans*b;
        }
    }
};