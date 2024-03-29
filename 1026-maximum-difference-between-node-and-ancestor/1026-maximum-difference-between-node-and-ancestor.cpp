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
    int maximumDifference = INT_MIN;
    
    void findMaxDiff(TreeNode *root, int maxi, int mini){
        if (root == NULL) return;
        
        maxi = max(maxi, root->val);
        mini = min(mini, root->val);
        
        maximumDifference = max(maximumDifference, maxi - mini);
        
        findMaxDiff(root->left, maxi,mini);
        findMaxDiff(root->right, maxi,mini);
        
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        findMaxDiff(root,maxi,mini);
        return maximumDifference;
    }
};
