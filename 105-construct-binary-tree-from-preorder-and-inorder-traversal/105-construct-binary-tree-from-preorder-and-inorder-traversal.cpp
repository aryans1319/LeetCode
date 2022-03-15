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
    TreeNode *constructTree(vector<int>&preorder,unordered_map<int,int>&mp,int start,int end,int &currentIndex){
        if(start > end) return NULL;
        TreeNode *rootNode = new TreeNode(preorder[currentIndex]);
        
        int inOindex = mp[preorder[currentIndex]];
        
        currentIndex++;
        
        rootNode->left = constructTree(preorder,mp,start,inOindex-1,currentIndex);
        rootNode->right = constructTree(preorder,mp,inOindex+1,end,currentIndex);
        
        return rootNode;
    }
    
    
    unordered_map<int,int>inorderIndex(vector<int>&inorder){
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return mp;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp = inorderIndex(inorder);
        int currentIndex = 0;
        return constructTree(preorder,mp,0,inorder.size()-1,currentIndex);
    }
};