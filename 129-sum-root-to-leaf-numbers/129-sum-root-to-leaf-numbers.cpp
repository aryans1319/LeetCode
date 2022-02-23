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
        stack<pair<TreeNode*,int>>st;
        st.push({root,0});
        int sum = 0;
        while(!st.empty()){
            auto [root,currentVal] = st.top();
            st.pop();
            currentVal = currentVal * 10 + root->val;
            if(!root->left && !root->right){
                sum+=currentVal;
            }
            if(root->right ){
                st.push({root->right,currentVal});
            }
            if(root->left ){
                st.push({root->left,currentVal});
            }
             
        }
        return sum;
    }
};