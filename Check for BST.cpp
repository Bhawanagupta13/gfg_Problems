#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    void inorder(Node* root,vector<int>&temp){
        if(!root) return;
        inorder(root->left,temp);
        temp.push_back(root->data);
        inorder(root->right,temp);
    }
    bool isBST(Node* root) {
        // Your code here
        if(!root->left && !root->right) return true;
        vector<int>temp;
        inorder(root,temp);
        for(int i=0;i<temp.size()-2;i++){
            if(temp[i]>temp[i+1]) return false;
            
        }
        return true;
    }
};