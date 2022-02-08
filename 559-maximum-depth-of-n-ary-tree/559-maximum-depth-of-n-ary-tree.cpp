/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(root == NULL){
            return 0;
        }
        int ans = 0;
        for(auto children : root->children){
            int tempAns = maxDepth(children);
            ans = max(ans,tempAns);
        }
        return ans+1;
    }
};