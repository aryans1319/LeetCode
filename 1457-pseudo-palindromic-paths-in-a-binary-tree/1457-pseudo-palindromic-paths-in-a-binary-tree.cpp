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
    int pseudoPalindromicPaths (TreeNode* root) {
        int count=0;
        vector<int>v(10,0);
        pseudo(root,v,count);
        return count;
    }
    void pseudo(TreeNode* root,vector<int> n,int &count){
        if(root==NULL)return;
        n[root->val]++;
        pseudo(root->left,n,count);
        pseudo(root->right,n,count);
        if(root->left==NULL and root->right==NULL){
            int flag=0;
            for(int i=1;i<=9;i++)
                if(n[i]&1)flag++;
            if(flag==1 or flag==0)count++;
        }
        n[root->val]--;
    }
};