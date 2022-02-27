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
    
        TreeNode *findLeftMostNode(TreeNode *cNode){
            while(cNode->left!=NULL){
                cNode = cNode->left;
            }
            return cNode;
        }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        if(root->val > key){
            root->left = deleteNode(root->left,key);
        }
        else if(root->val < key){
            root->right = deleteNode(root->right,key);
        }
        else{
            if(root->left == NULL && root->right == NULL){
                root = NULL;
                return root;
            }
            if(root->left!=NULL && root->right == NULL){
                root = root->left;
                return root;
            }
             if(root->right!=NULL && root->left == NULL){
                root = root->right;
                return root;
            }
            
            TreeNode *rightSubTree = root->right;
            TreeNode *tempNode = findLeftMostNode(root->right);
            
            int temp = root->val;
            root->val = tempNode->val;
            tempNode->val = temp;
            
            root->right = deleteNode(root->right,key);
            return root;
        }
        return root;
    }
      
};