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