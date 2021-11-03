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
 void findSum(TreeNode* root, int temp ,int &ans){
        if(root==NULL){
            return;
        }
        temp=temp*10+root->val;
        //If reached the last node
        if(root->left==NULL and root->right==NULL){
            ans+=temp;
        }
        findSum(root->left,temp,ans);
        findSum(root->right,temp,ans);
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        //Output
        int ans=0;
        findSum(root,0,ans);
        return ans;
    }
};