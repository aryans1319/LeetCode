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
    bool isValidBST(TreeNode* root) {
        long int prevVal = -99999999999;
        return isBST(root,prevVal);
    }
    
    bool isBST(TreeNode *root,long int &prev){
        if(root == NULL) return true;
        bool leftAns = isBST(root->left,prev);
        
        if(root->val <= prev){
            return false;
        }
        prev = root->val;
        bool rightAns = isBST(root->right,prev);
        return leftAns and rightAns;
    }
};