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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        
        ListNode *dummyNode = new ListNode(-101);
        ListNode *head = dummyNode;
        
        while(list1!=NULL && list2!=NULL){
             if(list1->val < list2->val){
                 ListNode *newNode = new ListNode(list1->val);
                 dummyNode->next = newNode;
                 list1=list1->next;
             }
            
             else{
                ListNode *newNode = new ListNode(list2->val);
                dummyNode->next = newNode;
                list2 = list2->next;
            }
            dummyNode = dummyNode->next;
        }
        
        if(list1!=NULL){
            dummyNode->next = list1;
        }
        if(list2!=NULL){
            dummyNode->next = list2;
        }
        
        return head->next;
    }
};