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
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            level+=1;
            int currentSize = q.size();
            for(int i=0;i<currentSize;i++){
            TreeNode *currentNode = q.front();
            q.pop();    
            if(currentNode->left!=NULL){
                q.push(currentNode->left);    
            }
             if(currentNode->right!=NULL){
                q.push(currentNode->right);    
            }
            }
        }
       return level;
    }
};