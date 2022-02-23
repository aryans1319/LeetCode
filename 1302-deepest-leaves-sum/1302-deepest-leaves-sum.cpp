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
    void deepestSum(TreeNode* root,int currentDepth,int &maxDepth,int &sum){
         if(root == NULL){
            return;
        }
         if(currentDepth > maxDepth)
            {
                maxDepth=currentDepth ;
                sum=0;
            }
            if(currentDepth == maxDepth){
                sum+=root->val;
            }
           
        deepestSum(root->left,currentDepth+1,maxDepth,sum);
        deepestSum(root->right,currentDepth+1,maxDepth,sum);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int maxDepth =0, ans= 0;
        deepestSum(root,0,maxDepth,ans);
        return ans;
    }
};