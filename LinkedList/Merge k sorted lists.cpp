/*
You are given an array of k linked - lists lists, each linked - list is sorted in ascending order. Merge all the linked - lists into one sorted linked - list and return it.

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6


Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []

*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        priority_queue< pair<int, ListNode*>, vector< pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        int k = arr.size();

        int i = 0;
        while (i < k) {
            if (arr[i] != NULL)
                pq.push({ arr[i]->val, arr[i] });
            i++;
        }


        ListNode* head = new ListNode(0);
        ListNode* ans = head;


        while (!pq.empty()) {
            ListNode* temp = pq.top().second;
            head->next = temp;
            head = head->next;
            pq.pop();
            if (temp->next) {
                pq.push({ temp->next->val, temp->next });
            }


        }

        //delete head;
        return ans->next;

    }
};