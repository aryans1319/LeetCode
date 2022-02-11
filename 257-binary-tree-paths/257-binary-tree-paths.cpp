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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        rootToLeaf(root,"",ans);
        return ans;
    }
    
    void rootToLeaf(TreeNode *root,string currentPath,vector<string>&ans){
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL && root->right == NULL){
            currentPath += to_string(root->val);
            ans.push_back(currentPath);
            return;
        }
        
        currentPath += to_string(root->val) + "->";
        
        rootToLeaf(root->left,currentPath,ans);
        rootToLeaf(root->right,currentPath,ans);
        return;
    }
};