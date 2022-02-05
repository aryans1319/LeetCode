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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
     if(lists.size() == 0){return NULL;}
        priority_queue<int, vector<int>, greater<int> > pq; 
        
        for(int i=0; i<lists.size(); i++){
            ListNode* temp = lists[i];
            while(temp != NULL){
                pq.push(temp->val);  //insert all the elements in to queue.
                temp = temp->next;
            }
        }
        
        if(pq.size() == 0){ return NULL;}    //if queue is empty, it means there is no element in the given list so return NULL
        
        ListNode* head = new ListNode(pq.top()); 
        pq.pop();
        ListNode* tail = head;
        while(!pq.empty()){
            ListNode* temp = new ListNode(pq.top());
            tail->next = temp;
            tail = tail->next;
            pq.pop();
        }
        return head;
    }
};