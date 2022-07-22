class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *fdum = new ListNode(0), *bdum = new ListNode(0),
                 *front = fdum, *back = bdum, *curr = head;
        while (curr) {
            if (curr->val < x) front->next = curr, front = curr;
            else back->next = curr, back = curr;
            curr = curr->next;
        }
        front->next = bdum->next, back->next = nullptr;
        return fdum->next;
    }
};