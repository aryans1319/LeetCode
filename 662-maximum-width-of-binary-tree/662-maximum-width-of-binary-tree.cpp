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
        if(root == NULL){
            return 0;
        }
        int ans = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            int size = q.size();
            int mini = q.front().second;
            int first,last;
            for(int i = 0 ; i < size; i++){
                unsigned int currentMin = q.front().second - mini;
                TreeNode *node = q.front().first;
                q.pop();
                
                if(i == 0) first = currentMin;
                if(i == size-1) last = currentMin;
                
                if(node->left!=NULL){
                    q.push({
                        node->left, currentMin*2+1
                    });
                }
                if(node->right!= NULL){
                    q.push({
                        node->right, currentMin*2+2
                    });
                }
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};