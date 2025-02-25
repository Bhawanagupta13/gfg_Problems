#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    return new Node(val);
}


// } Driver Code Ends
/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        // Your code here
        vector<vector<int>>result;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>ans;
            Node* curr=q.front();
            q.pop();
            ans.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            result.push_back(ans);
            
        }
        return result;
    }
};