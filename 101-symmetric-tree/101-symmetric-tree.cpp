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
    /* 
        Symmetric binary trees means it forms a mirror image 
        of itself around the centre & if mirror image is imposed
        on the other then it's a symmetric tree!
        
        Now from the property of mirror image if anything appears 
        left then it's seems to be in right of mirror and vice-versa
        
        if we perform a inorder traversal on the left subtree (root, left ,             right) then on the right subtree it would look as (root,right,left)
        
        And if we compare the node values while performing the traversal,
        they would be same if the trees are symmetric otherwise they aren't
        symmetric
    
    */
    bool isSymmetricHelp(TreeNode *left, TreeNode *right){
        if(left == NULL && right == NULL){
            return true;
        }
        else if(left == NULL || right == NULL){
            return false;
        }
        else if(left->val != right->val){
            return false;
        }
        return isSymmetricHelp(left->left, right->right) &&                             isSymmetricHelp(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isSymmetricHelp(root->left, root->right);
    }
};