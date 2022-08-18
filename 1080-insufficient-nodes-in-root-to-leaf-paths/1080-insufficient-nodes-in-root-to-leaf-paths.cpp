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
    bool deletedPaths(TreeNode *root, int limit, int currentSum){
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL && currentSum + root->val >= limit){
            // currentSum+=root->val;
            return false;
        }
        if(root->left == NULL && root->right == NULL && currentSum + root->val < limit){
            return true;
        }
        bool leftSubtree = false;
        bool rightSubtree = false;
        leftSubtree = deletedPaths(root->left, limit, currentSum + root->val);
        rightSubtree = deletedPaths(root->right, limit, currentSum + root->val);
        
        if(leftSubtree){
            root->left = NULL;
        }
        if(rightSubtree){
            root->right = NULL;
        }
        return leftSubtree && rightSubtree;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(root == NULL) return root;
        if(deletedPaths(root,limit,0)){
            return NULL;
        }
        return root;
        
    }
};