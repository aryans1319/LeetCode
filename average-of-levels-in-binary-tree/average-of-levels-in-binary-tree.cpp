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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode *>q;
        if(root)
        q.push(root);
        while(q.size()){
            int x=q.size();
            int y=x;
            double sum=0.0;
            while(x--){
                auto a=q.front();
                if(a->left)q.push(a->left);
                if(a->right)q.push(a->right);
                q.pop();
                sum+=a->val;
                
            }
            ans.push_back(sum/y);
        }
        return ans;
    }
};