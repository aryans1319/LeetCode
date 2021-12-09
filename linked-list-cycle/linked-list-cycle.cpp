/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> st;
        ListNode *curr = head;
        
        while(curr){
            st.insert(curr);
            curr=curr->next;
            if(st.find(curr)!=st.end()){
            return true;
        }
        } 
        return false;
       
    }
};