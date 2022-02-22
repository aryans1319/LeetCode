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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        TreeNode *currentNode = root;
        vector<int>ans;
        
        while(true){
            if(currentNode!=NULL){
                st.push(currentNode);
                currentNode = currentNode->left;
            }
            else{
                if(st.empty() == true) break;
                currentNode = st.top();
                st.pop();
                ans.push_back(currentNode->val);
                currentNode = currentNode->right;
            }
        }
        return ans;
    }
};