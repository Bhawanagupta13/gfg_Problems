class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            while(s.size()>0 && arr[s.top()] >= arr[i]){
                s.pop();
            }
            right[i]=s.empty() ? n: s.top();
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }