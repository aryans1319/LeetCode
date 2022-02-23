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
    int sumNumbers(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int sum = 0;
        while(!q.empty()){
            auto [root,currentVal] = q.front();
            q.pop();
            currentVal = currentVal * 10 + root->val;
            if(root->left!=NULL){
                q.push({root->left,currentVal});
                
            }
            if(root->right!=NULL){
                q.push({root->right,currentVal});
            }
            if(root->left==NULL && root->right==NULL){
                sum+=currentVal;
            }
             
        }
        return sum;
    }
};