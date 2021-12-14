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
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverseLinkedListInGroups(head,k);
    }
    
    ListNode *reverseLinkedListInGroups(ListNode*head,int k){
        if(head == NULL){
            return head;
        }
        ListNode *current = head;
        int currentLength =1;
        
        while(current->next!=NULL && currentLength < k){
            current = current->next;
            currentLength+=1;
        }
            if(currentLength < k){
                return head;
            }
        ListNode *tempNode = current->next;
        current->next = NULL;
        
        /*Reversing the Linked List*/
        ListNode *prev = NULL;
        current = head;
        while(current!=NULL){
            ListNode *temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        /*--------------------------*/
        
        ListNode *tempList = reverseLinkedListInGroups(tempNode,k);
        head->next = tempList;
        return prev;
    }
};