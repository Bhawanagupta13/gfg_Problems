#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends
// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
    unordered_map<int,int>mp;
    Node* solve(vector<int> &preorder,int s,int e,int &preInd){
        if(s>e) return NULL;
        int val=preorder[preInd];
        Node* root=new Node(preorder[preInd++]);
        
        root->left=solve(preorder,s,mp[val]-1,preInd);
        root->right=solve(preorder,mp[val]+1,e,preInd);
        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int preInd=0;
        return solve(preorder,0,inorder.size()-1,preInd);
    }
};