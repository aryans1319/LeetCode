class Solution {
public:
    Node* connect(Node* root) {
        // support variables
        Node *currParent = root, *baseChild, *currChild, *nextChild;
        while (currParent) {
            // skipping childless parents - get a family - up to the last node
            while (currParent->next && !currParent->left && !currParent->right) currParent = currParent->next;
            // setting the new basechild, provided we have one at all
            currChild = baseChild = currParent->left ? currParent->left : currParent->right;
            while (currChild) {
                // getting nextChild - either the right sibling of currChild or...
                if (currParent->right && currChild != currParent->right) nextChild = currParent->right;
                // the child of a following parent
                else {
                    // moving to the nextParent, if any
                    currParent = currParent->next;
                    // moving parents, if we have too
                    while (currParent && !currParent->left && !currParent->right) currParent = currParent->next;
                    // setting nextChild to be the next left/right child, if any; NULL otherwise
                    nextChild = currParent ? currParent->left ? currParent->left : currParent->right : currParent;
                }
                currChild->next = nextChild;
                currChild = nextChild;
            }
            // preparing for the next loop
            currParent = baseChild;
        }
        return root;
    }
};