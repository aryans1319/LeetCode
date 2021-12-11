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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummyNode = new ListNode(101);
        dummyNode->next = head;
        
        ListNode *prev = dummyNode;
        ListNode *curr = head;
        
        while(curr!=NULL){
            if(curr->val==prev->val){
                prev->next = curr->next;
                curr=curr->next;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        return dummyNode->next;
    }
};