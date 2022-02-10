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
    void addLeftSubtree(TreeNode *currentNode, stack<TreeNode*>&st){
        st.push(currentNode);
        while(currentNode->left!=NULL){
            st.push(currentNode->left);
            currentNode = currentNode->left;
        }
        return;
    } 
        
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>answer;
        stack<TreeNode*>st;
        
        if(root == NULL)
        {
            return answer;
        }
        
        addLeftSubtree(root,st);
        while(!st.empty()){
            TreeNode *currentNode = root;
            currentNode = st.top();
            st.pop();
            answer.push_back(currentNode->val);
            if(currentNode->right!=NULL){
                addLeftSubtree(currentNode->right,st);
        }
        }
        return answer;
    }
};