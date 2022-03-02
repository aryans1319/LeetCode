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
    unordered_map<int,int> populateMap(vector<int>&inorder){
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return mp;
    }
    
    TreeNode* constructTree(vector<int>& preorder,unordered_map<int,int>&mp,int start,int end,int &preIndex){
        if(start > end) return NULL;
        TreeNode *root = new TreeNode(preorder[preIndex]);
        
        int currentIndex = mp[preorder[preIndex]];
        preIndex--;
        root->right = constructTree(preorder,mp,currentIndex+1,end,preIndex);
        root->left = constructTree(preorder,mp,start,currentIndex-1,preIndex);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         unordered_map<int,int> mp = populateMap(inorder);
        int preIndex = postorder.size()-1;
        return constructTree(postorder,mp,0,inorder.size()-1,preIndex);
    }
};