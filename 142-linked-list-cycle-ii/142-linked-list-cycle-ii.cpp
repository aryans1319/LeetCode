/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        
        ListNode *slow=head,*fast=head;
        
        //cycle checking
        do{
            //move slow by one
            slow = slow->next;
            if(!slow) break;
            
            //move fast by 2
            fast= fast->next;
            if(!fast) break;
            fast = fast->next;
            if(!fast) break;            
            
        }while(slow!=fast);
        //no cycle
        if(!slow or !fast)
            return NULL;
        
        //check the entry point
        fast = head;
        while(fast !=slow)
            fast=fast->next, slow=slow->next;
        return fast; 
    }
};