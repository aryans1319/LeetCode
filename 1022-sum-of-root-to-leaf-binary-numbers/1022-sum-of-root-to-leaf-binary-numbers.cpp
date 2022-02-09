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
    void rootToLeaf(TreeNode *root, string currentString, int ans[1]){
        if(root->left == NULL && root->right == NULL){
            currentString+=to_string(root->val);
            ans[0] += stoi(currentString,0,2);
            return;
        }
        string cur = to_string(root->val);
        if(root->left!=NULL){
            rootToLeaf(root->left,currentString + cur,ans);
        }
        if(root->right!=NULL){
            rootToLeaf(root->right,currentString+cur,ans);
        }
        return;
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans[1];
        ans[0] = 0;
        rootToLeaf(root,"",ans);
        return ans[0];
    }
};