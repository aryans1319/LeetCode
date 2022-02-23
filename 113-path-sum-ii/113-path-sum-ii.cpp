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
    void dfs(TreeNode *root, int targetSum, vector<int>&currentPath,vector<vector<int>>&ans){
        if(root == NULL){
            return;
        }
        currentPath.push_back(root->val);
        targetSum-=root->val;
         if(root->left == NULL && root->right== NULL && targetSum == 0)
        {
            ans.push_back(currentPath);
        }
        dfs(root->left,targetSum,currentPath,ans);
        dfs(root->right,targetSum,currentPath,ans);
        currentPath.pop_back();
        return;
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>currentPath;
        dfs(root,targetSum,currentPath,ans);
        return ans;
    }
};