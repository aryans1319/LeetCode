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
    TreeNode* invertTree(TreeNode* root) {
        if (root==NULL){
            return root;
        }
        
        TreeNode *leftSub = invertTree(root->left);
        TreeNode *rightSub = invertTree(root->right);
        
        root->left = rightSub;
        root->right = leftSub;
        
        return root;
    }
};