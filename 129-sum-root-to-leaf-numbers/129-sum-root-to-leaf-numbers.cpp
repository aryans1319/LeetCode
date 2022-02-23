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
    int getRootToLeafSum(TreeNode *root,int nodeVal){
        if(root == NULL){
            return 0;
        }
          
        nodeVal = (nodeVal * 10) + root->val;
        if(root->left == NULL && root->right == NULL){
            return nodeVal;
        }
      
        int leftSubtreeSum = getRootToLeafSum(root->left,nodeVal);
        int rightSubtreeSum = getRootToLeafSum(root->right,nodeVal);
        
        return leftSubtreeSum + rightSubtreeSum;
    }
    
    int sumNumbers(TreeNode* root) {
        return getRootToLeafSum(root,0);
    }
};