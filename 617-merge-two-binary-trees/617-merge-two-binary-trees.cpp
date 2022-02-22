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
     TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2) return nullptr;
        if(!t1 || !t2) return t1? t1:t2;

        queue<TreeNode*> q1,q2;
        q1.push(t1);
        q2.push(t2);
        
        while(!q1.empty() && !q2.empty()){
            TreeNode* c1(q1.front());
            TreeNode* c2(q2.front());
            q1.pop();
            q2.pop();
            
            c1->val+=c2->val;
            
            if(!c1->left && c2->left) c1->left = c2->left;
            else if(c1->left && c2->left) { q1.push(c1->left); q2.push(c2->left); }
            
            if(!c1->right && c2->right) c1->right = c2->right;
            else if(c1->right && c2->right) { q1.push(c1->right); q2.push(c2->right); }
        }
        return t1;
    }
};