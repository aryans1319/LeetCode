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
    /*
    The approach here to track the traversal from left to right and right to left
    is to keep a bool value, set it true(0) L->R and false(1) R->L
    if true insert at current index i else insert from the end
    Rest everything remains same!
    */
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool leftToRight = true;
        
        while(!q.empty()){
            int size = q.size();
            vector<int>rows(size);
            
            for(int i = 0; i<size; i++){
                TreeNode *node = q.front();
                q.pop();
                
                int index = (leftToRight) ? i : (size-i-1);
                rows[index] = node->val;
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            leftToRight = !leftToRight;
            ans.push_back(rows);
        }
        return ans;
    }
};