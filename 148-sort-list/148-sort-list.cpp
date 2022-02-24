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
    ListNode *middleNode(ListNode *head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
        }
    
    ListNode *mergeSort(ListNode *l1, ListNode *l2){
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        
        ListNode *current1 = l1;
        ListNode *current2 = l2;
        
        ListNode *dummyNode = new ListNode(-1);
        ListNode *prev = dummyNode;
        
        while(current1!=NULL && current2!=NULL){
            if(current1->val < current2->val){
                prev->next = current1;
                current1 = current1->next;
            }
            else{
                prev->next = current2;
                current2 = current2->next;
            }
            prev = prev->next;
        }
        prev->next= current1!=NULL ? current1 : current2;
        return dummyNode->next;
    }
    
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *mid = middleNode(head);
        ListNode *nHead = mid->next;
        mid->next=NULL;
        ListNode *firstHalf = sortList(head);
        ListNode *secondHalf = sortList(nHead);
        return mergeSort(firstHalf,secondHalf);
    }
};