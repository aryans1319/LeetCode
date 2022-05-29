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
    int height(TreeNode *root){
        if(root == NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return 1 + max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int maxi = 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        int totalHeight = leftHeight + rightHeight;
        // maxi = max(maxi,rightHeight+leftHeight);
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
        return max(totalHeight , max(leftDiameter, rightDiameter));
        
    }
};