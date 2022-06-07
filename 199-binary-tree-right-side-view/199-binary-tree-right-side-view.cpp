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
  void getRightView(TreeNode *node,vector<int>&ans,int level){
    if(node == NULL) return;
    if(level == ans.size()) {
        ans.push_back(node->val);
    } 
    getRightView(node->right,ans,level+1);
    getRightView(node->left,ans,level+1);
} 
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        int level = 0;
        getRightView(root,ans,level);
        return ans;
    }
};