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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL) return root2;
        if(root2 == NULL) return root1;
        if(root1==NULL && root2 ==NULL) return NULL;
        
        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root1,root2});
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            
            /* if the right subtree is not null or the root of the right sub-tree (either left or right isnt null)
               then we will process further */ 
            
            if(temp.second!=NULL){
                temp.first->val += temp.second->val;
            
            
            /* if the left node of the first subtree is null we can just point the left node of second tree to the
               left node of the first subtree */ 
            
            if(temp.first->left == NULL){
                temp.first->left = temp.second->left;
            }
            else{
                q.push({temp.first->left,temp.second->left});
            }
            
             /* if the right node of the first subtree is null we can just point the right node of second tree to the
               right node of the first subtree */ 
            
            if(temp.first->right == NULL){
                temp.first->right = temp.second->right;
            }
            else{
                q.push({temp.first->right,temp.second->right});
            }
            }
        }
        return root1;
    }
};