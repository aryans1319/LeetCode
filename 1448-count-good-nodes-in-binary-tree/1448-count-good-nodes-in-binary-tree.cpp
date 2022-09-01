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
    int goodNodes(TreeNode* root) {
        int count = 0;
        stack<pair<TreeNode*, int>> st;
        st.push({root,root->val});
        while (!st.empty()) {
            TreeNode* node = st.top().first;
            int maxValue = st.top().second;
            st.pop();

            if (maxValue <= node->val) {
                count++;
                maxValue = node->val;
            }

            if (node->right != NULL) {
                st.push({node->right, maxValue});
            }
            if (node->left != NULL) {
                st.push({node->left, maxValue});
            }
        }

        return count;
    }
};