/*
You are given an array of k linked - lists lists, each linked - list is sorted in ascending order. Merge all the linked - lists into one sorted linked - list and return it.



Example 1:

Input: lists = [[1, 4, 5], [1, 3, 4], [2, 6]]
Output : [1, 1, 2, 3, 4, 4, 5, 6]
Explanation : The linked - lists are :
[
	1->4->5,
	1->3->4,
	2->6
]
Merging them into one sorted list :
1->1->2->3->4->4->5->6

Example 2 :

Input : lists = []
Output : []
Example 3 :

Input : lists = [[]]
Output : []

*/


class Solution {
public:
    typedef pair<int, ListNode*> pp;

    ListNode* mergeKLists(vector<ListNode*>& arr) {


        priority_queue< pp, vector<pp>, greater<pp>> min_heap;   // declaring a minheap to find the smallest of k elements.
        
	   int k = arr.size();
        int i = 0;

        while (i < k) {            // loop to store first element of k lists in minheap.
            if (arr[i] != NULL)
                min_heap.push({ arr[i]->val, arr[i] });
            i++;
        }


        ListNode* dummy= new ListNode(0);
        ListNode* head = dummy;


        while (!min_heap.empty()) {               // loop to form a linked list.
            ListNode* curr__node = min_heap.top().second; // curr_node will point to the current smallest in the list.
            dummy->next =  curr_node;
            dummy= dummy->next;
            min_heap.pop();
            if ( curr_node->next) {             //  if next of the curr_node is not NULL then we will push it into the minheap.
                min_heap.push({ curr_node->next->val, curr_node->next });
            }

        }


        return head->next;

    }
};