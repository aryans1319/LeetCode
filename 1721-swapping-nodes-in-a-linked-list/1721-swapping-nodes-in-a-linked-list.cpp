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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *runner = head;
        ListNode *prevNode = NULL;
        
        for(int i =1;i<k+1;i++){
            prevNode=runner;
            runner=runner->next;
        }
        ListNode *follower = head;
        
        while(runner!=NULL){
            runner=runner->next;
            follower = follower->next;
            
        }
        swap(prevNode->val,follower->val);
        return head;
    }
};