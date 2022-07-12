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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *dummy = new ListNode();
        
        ListNode *prevNode = dummy;
        ListNode *currentNode = head;
        
        while(currentNode && currentNode->next){
            
            //swapping
            prevNode->next = currentNode->next;
            currentNode->next = prevNode->next->next;
            prevNode->next->next = currentNode;
            
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
        
        return dummy->next;
    }
};