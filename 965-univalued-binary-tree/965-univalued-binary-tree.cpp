/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSame(TreeNode *root, int currentVal){
        if(root == NULL) return true;
        
        if(root->val != currentVal) return false;
        
        int left = isSame(root->left,currentVal);
        int right = isSame(root->right,currentVal);
        
        return left && right;
    }
    bool isUnivalTree(TreeNode* root) {
        return isSame(root,root->val);
    }
};