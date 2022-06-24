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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *node = head;
        int size = 0;
        while(node != NULL){
            size++;
            node = node->next;
        }
        if(size == n) return head->next;
        int it = size - n;
  
        ListNode *dummy = head;
        ListNode *dummyHead = dummy;
        for(int i=1 ; i<it;i++){
            dummy=dummy->next;
        }
        dummy->next = dummy->next->next;
        return dummyHead;
    }
};