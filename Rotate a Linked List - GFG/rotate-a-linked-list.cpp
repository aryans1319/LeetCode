// { Driver Code Starts
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

/*
    There can be two cases : 
    1.) K < length 2.) K >= length
    
    if K is greater or equal to the length of the list
    Suppose for eg : K = 5 and given list is:
    
    1->2->3->4->5
    
    After 5 rotation it would be the same list only, after 10 also, after
    15 also i.e list is same if K is a multiple of linkedlist length
    
    Now, suppose K = 12
    
    The first 10 rotation would give back the same list, we just need to do
    2 rotations, extra - so can we conclude that we need to do (K % length) no
    of rotations 12 % 5 i.e 2 rotations , so K = K % len
    
    value[] = {2, 4, 7, 8, 9} k = 3 , shift left 
    
    Rotate 1: 4 -> 7 -> 8 -> 9 -> 2
    Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
    Rotate 3: 8 -> 9 -> 2 -> 4 -> 7
    
    break link of 7 point it to NULL , assign last->next (last will be the node till K) to head
    
    Steps:
    
    1) Find length 
    2) Traverse upto K, find last node point it to head
    3) Break link of node after K, point it to NULL
    
    TC : O(N) + O(N - (N+K) 
    SC : O(1)
 
 */

class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // if(head == NULL || head->next == NULL) return head;
        
        Node *curr = head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next = head;
    
        while(k>0){
            curr = curr->next;
            k--;
        }
        Node *prev = curr;
        head = prev->next;
        prev->next = NULL;
        
        return head;
    }
};
    


// { Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}
  // } Driver Code Ends