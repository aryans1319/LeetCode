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
    void rightView(TreeNode *root,int level,set<int>&hashSet,vector<int>&ans){
    if(root == NULL){
        return;
    }
    
    if(hashSet.find(level) == hashSet.end()){
        hashSet.insert(level);
        ans.push_back(root->val);
    }
    rightView(root->right,level+1,hashSet,ans);
    rightView(root->left,level+1,hashSet,ans);
    return;
    
}
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        set<int>hashSet;
        rightView(root,0,hashSet,ans);
        return ans;
    }
};