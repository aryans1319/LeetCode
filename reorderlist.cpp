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
        ListNode* getMid(ListNode* head)
    {
        ListNode *slow,*fast;
        slow = fast = head;
        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
            slow=slow->next;
            fast = fast->next->next;
        }
        return slow;
        
    }
    
     ListNode* getReverse(ListNode* head)
    {
        ListNode *cur,*prev;
        cur=head;
        prev = NULL;
        while(cur!=NULL)
        {
            ListNode *temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL)return;
        
        ListNode *mid=getMid(head);
        
         ListNode* secondHalf = mid->next;
        mid->next=NULL;
        
        ListNode *revsec=getReverse(secondHalf);
        
        while(head!=NULL && revsec!=NULL){
            ListNode *temp=head->next;
            head->next=revsec;
            revsec=revsec->next;
            head->next->next=temp;
            head=temp;
        }
    }
};
