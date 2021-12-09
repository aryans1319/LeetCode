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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
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
        while(l1&& l2){
            int firstVal = l1->val;
            int secondVal = l2->val;
            
            total = firstVal + secondVal + carry;
            carry = total/10;
            int res= total%10;
             l1=l1->next;
            l2=l2->next;
                        
            ListNode *newNode = new ListNode(res);
            dummyNode->next = newNode;
            
            dummyNode=dummyNode->next;
           
        }
        
        while(l1){
            int total = l1->val + carry;
            
        
            carry = total/10;
            int res = total % 10;
             l1 = l1->next;
            
            ListNode *newNode = new ListNode(res);
            dummyNode->next = newNode;
            dummyNode = dummyNode->next;
           
        }
        while(l2){
           int total = l2->val + carry;
            
           
                carry = total/10;
                int res = total %10;
                l2 = l2->next;
            
            ListNode *newNode = new ListNode(res);
            dummyNode->next = newNode;
            dummyNode = dummyNode->next;
            
        }
        if(carry){
            ListNode *newNode = new ListNode(1);
            dummyNode->next = new ListNode(carry);
            
        }
        return head->next;
    }
};