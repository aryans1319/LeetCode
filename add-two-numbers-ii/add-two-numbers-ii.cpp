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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        
        while(curr!=NULL){
            ListNode *tempNode = curr->next;
            curr->next=prev;
            prev=curr;
            curr=tempNode;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseList(l1);
        l2=reverseList(l2);
        ListNode *dummyNode = new ListNode(-1);
      
        ListNode *head = dummyNode;
        if(l1 == NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }

        int carry = 0;
        int total = 0;
        while(l1 ||  l2){
            int firstVal = l1 ? l1->val : 0;
            int secondVal = l2 ? l2->val : 0;
            
            total = firstVal + secondVal + carry;
            carry = total/10;
            int res= total%10;
             l1= l1? l1->next :l1;
            l2= l2 ? l2->next : l2;
                        
            ListNode *newNode = new ListNode(res);
            dummyNode->next = newNode;
            
            dummyNode=dummyNode->next; 
        }
        
        if(carry){
            ListNode *newNode = new ListNode(1);
            dummyNode->next = newNode;
            
        }
        return reverseList(head->next); 
    }
};