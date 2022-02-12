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
    bool isSymmetric(TreeNode* root) {
        return symTrees(root->left,root->right);
    }
    
    bool symTrees(TreeNode* t1, TreeNode *t2){
        if(t1 == NULL && t2 == NULL){
            return true;
        }
        
        if(t1 == NULL || t2 == NULL || t1->val!=t2->val){
            return false;
        }
        
        return symTrees(t1->left,t2->right) && symTrees(t1->right,t2->left);
    }
};