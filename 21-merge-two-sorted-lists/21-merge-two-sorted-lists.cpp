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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        ListNode *newList = new ListNode(-1);
        ListNode *dummy = newList;
        ListNode *head1 = l1;
        ListNode *head2 = l2;
        while(head1 != NULL && head2!= NULL){
            if(head1->val > head2->val){
                dummy->next = head2;
                head2 = head2->next;
            }
            else{
                dummy->next = head1;
                head1 = head1->next;
            }
            dummy = dummy->next;
        }
        if(head1!=NULL){
            dummy->next = head1;
        }
        if(head2!=NULL){
            dummy->next = head2;
        }
        return newList->next;
    }
};