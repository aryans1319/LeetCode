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
    int countNode(ListNode *head){
        int n = 0;
        ListNode *curr = head;
        while(curr!=NULL){
            curr = curr->next;
            n++;
        }
        return n;
    }
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *dummy=head;
        int totalNode = countNode(head);
        int middleNode = floor(totalNode/2);
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            delete head;
            return NULL;
        }
        while(middleNode-->1){
            head=head->next;

        }
        head->next=head->next->next;        
        return dummy;
    }
};