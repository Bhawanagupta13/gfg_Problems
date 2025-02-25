#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        // Your code here
        if(!head || !head->next || k==0) return head;
        Node* temp=head;
        int n=1;
        while(temp->next){
            temp=temp->next;
            n++;
        }
        k=k%n;
        if(k==0) return head;
        temp->next=head;
        Node* t=head;
        while(k>1){
            t=t->next;
            k--;
        }
        head=t->next;
        
        t->next=NULL;
        return head;
    }
};