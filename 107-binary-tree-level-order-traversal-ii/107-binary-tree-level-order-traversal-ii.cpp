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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        vector<vector<int>>a;
        if(root == NULL) return a;
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>level;
            for(int i=0; i<size; i++){
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            ans.insert(ans.begin(), level);
        }
        
        return ans;
    }
};