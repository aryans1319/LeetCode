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
    int maxHeight(TreeNode *root){
        if(root == NULL) return 0;
        int left = maxHeight(root->left);
        int right = maxHeight(root->right);
        
        return 1 + max(left,right);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int left = maxHeight(root->left);
        int right = maxHeight(root->right);
        
        if(left == right) return root;
        else if(left > right) return lcaDeepestLeaves(root->left);
        else return lcaDeepestLeaves(root->right);
    }
};