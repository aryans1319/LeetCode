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
    bool isIdentical(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        
        if(p==NULL || q==NULL || p->val!=q->val){
            return false;
        }
        
        return isIdentical(p->left,q->left) && isIdentical(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        /* 
        if the subroot/subtree we want to find in tha main tree is null
        then obviously the main tree has subroot present, because even
        if the subtree is null, the main tree contains it
        */
           
        if(subRoot == NULL){
            return true;
        }
        if(root == NULL){
            return false;
        }
        
        if(isIdentical(root,subRoot)){
            return true;
        }
        return (isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
    }
};