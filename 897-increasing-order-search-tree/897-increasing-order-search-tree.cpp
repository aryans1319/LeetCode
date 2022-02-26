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
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>traversal;
        dfsInorder(root,traversal);
        TreeNode *dummyNode = new TreeNode(-1);
        TreeNode *currentNode = dummyNode;
        
        for(auto it : traversal){
            dummyNode->right = new TreeNode(it);
            dummyNode = dummyNode->right;
        }
        return currentNode->right;
     }
    
    void dfsInorder(TreeNode*root,vector<int>&ans){
        if(root == NULL){
            return;
        }
        dfsInorder(root->left,ans);
        ans.push_back(root->val);
        dfsInorder(root->right,ans);
        return;
    }
};