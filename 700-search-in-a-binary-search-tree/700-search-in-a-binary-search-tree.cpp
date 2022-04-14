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
    TreeNode* searchBST(TreeNode* root, int val) {
        
        // o(n)
        // if(root == NULL) return NULL;
        // if(root->val == val){
        //     return root;
        // }
        // else if(root->val < val){
        //     return searchBST(root->right,val);
        // }
        // else {
        //     return searchBST(root->left,val);
        // }
       
        
        // without recursion
        TreeNode *currentNode = root;
        while(currentNode != NULL){
            if(currentNode->val == val)
                return currentNode;
            else if (currentNode->val < val)
                currentNode = currentNode->right;
            else
                currentNode = currentNode->left;
        }
        return currentNode;
    }
};