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
    ListNode* help(ListNode* head){
        if(head->next==NULL){
            return head;
        }
        ListNode *newHead=help(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }
    
    ListNode* reverseList(ListNode* head) {
            if(head==NULL)return head;
        return help(head);
    }
};