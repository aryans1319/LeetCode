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
    int check(TreeNode *root,long pre,int &targetSum){
if(!root) return 0;
long currentSum = pre + root->val;
return  (currentSum == targetSum) +check(root->left, currentSum, targetSum) +check(root->right, currentSum, targetSum);
}

    int pathSum(TreeNode* root, int targetSum) {
        if(root== NULL) return 0;
        return check(root, 0 ,  targetSum) +  pathSum(root->left, targetSum) + pathSum(root->right, targetSum);

    }
};