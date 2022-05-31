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
        We can follow a post-order traversal approach here to solve the 
        problem, in this we just need to swap the link for the left and right
        pointers and thus invert our binary tree
        
    */
    void swap(TreeNode *root){
        if(root == NULL) return;
        
        swap(root->left);
        swap(root->right);
        
        /* Swap Function */
        
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        swap(root);
        return root;
    }
};