#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << "\n~\n";
}

Node *insertSorted(Node *head, int data) {
    Node *new_node = new Node(data);
    if (!head || head->data >= data) {
        new_node->next = head;
        return new_node;
    }

    Node *current = head;
    while (current->next && current->next->data < data) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}


// } Driver Code Ends
/* Link list Node
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
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        if(!head1) return head2;
        if(!head2) return head1;
        Node* temp;
        if(head1->data<head2->data){
            temp=head1;
            head1=head1->next;
        }
        else{
            temp=head2;
            head2=head2->next;
        }
        Node* newhead=temp;
        while(head1 && head2){
            if(head1->data<head2->data){
            temp->next=head1;
            head1=head1->next;
        }
        else{
            temp->next=head2;
            head2=head2->next;
        }
        temp=temp->next;
        }
        if(!head1) temp->next=head2;
        if(!head2) temp->next=head1;
        return newhead;
    }
};