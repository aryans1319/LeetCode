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
    int ans = 0;
    int preOrder(TreeNode *root){
        if(root == NULL) return 0;
        int left = preOrder(root->left);
        int right = preOrder(root->right);
        ans += abs(left-right);
        return left+right+root->val;
    }
    int findTilt(TreeNode* root) {
        preOrder(root);
        return ans;
    }
};