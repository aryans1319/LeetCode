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
    bool isUnivalTree(TreeNode* root) {
       if(root == NULL) return true;
       if(root->left == NULL && root->right == NULL) return true;
        
       queue<TreeNode*>q;
       // the first step in every BFS approach push the root node into the queue 
       q.push(root);
        while(!q.empty()){
            
            int currentSize = q.size();
            //iterating for current queue
            for(int i=0;i<currentSize;i++){
    
                TreeNode *currentNode = q.front();
                q.pop();
        /* made a currentNode pointer pointing to the front element of queue
       and in each and every step after pushing the children of every node just
       check if the currentNode value and root value of that particular node are          same if not return false*/
                if(currentNode->val!=root->val){
                    return false;
                }
                /* if left child exist push into the queue*/
                
                if(currentNode->left!=NULL){
                    q.push(currentNode->left);
                }
                 
                /* if right child exist push into the queue*/
                
                 if(currentNode->right!=NULL){
                    q.push(currentNode->right);
                }
            }
        }
        return true;
    }
};