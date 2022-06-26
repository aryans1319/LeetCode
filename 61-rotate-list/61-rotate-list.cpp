/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //edge cases
        if(!head || !head->next || k==0)return head;
        
        //count length of linked-list
        ListNode *curr=head;
        int len=1;
        while(curr->next && ++len){
            curr=curr->next;
        }
        
        //going till that node
        curr->next=head;
        k=k%len;
        k=len-k;
        while(k--)curr=curr->next;
        
        //make the node as head and break the connection
        head=curr->next;
        curr->next=NULL;
        return head;
        
    }
};