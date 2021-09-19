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
    bool checkBal(TreeNode *p,TreeNode *q){
        if(p==NULL || q==NULL){
            return (p==q);
        }
        
        return(p->val==q->val)&& checkBal(p->left,q->right)&& checkBal(p->right,q->left);
    }
    
    bool isSymmetric(TreeNode* root) {
       if(!root) return true;
        return checkBal(root->left,root->right);    
    }
};