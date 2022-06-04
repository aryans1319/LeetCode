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
    int widthOfBinaryTree(TreeNode* root) {
         int ans=0;
            if(!root)
               return ans;
                    queue<pair<TreeNode *,int>>q;
            q.push({root,0});
            while(!q.empty())
            {
                   int s=q.size();
                    int last,first;
                    int mini=q.back().second;
                    for(int i=0;i<s;i++)
                    {
                            int cur_i = q.front().second-mini;
                            TreeNode *n = q.front().first;
                            q.pop();
                            if(i==0) first= cur_i;
                            if(i==s-1) last=cur_i;
                            if(n->left) q.push({n->left,cur_i*2});
                            if(n->right) q.push({n->right,cur_i*2 +1});
                    }
                    ans = max(ans,last-first+1);
            } 
            return ans;
    }
};