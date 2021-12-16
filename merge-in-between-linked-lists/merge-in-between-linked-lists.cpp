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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        a = a-1; 
        b=b+1;
        ListNode *start = list1;
        ListNode *end = list1;
        
        ListNode *tail = list2;
        
        while(a--){
            start = start->next;
        }
        while(b--){
            end=end->next;
        }
        while(tail->next!=NULL){
            tail=tail->next;
        }
        
        start->next = list2;
        tail->next = end;
        
        return list1;
    }
};