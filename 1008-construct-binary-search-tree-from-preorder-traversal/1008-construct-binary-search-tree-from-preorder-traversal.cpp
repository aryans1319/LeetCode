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
        preIndex++;
        
        root->left = constructTree(preorder,mp,start,currentIndex-1,preIndex);
        root->right = constructTree(preorder,mp,currentIndex+1,end,preIndex);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder(preorder.size());
        for(int i=0;i<preorder.size();i++){
            inorder[i] = preorder[i];
        }
        sort(inorder.begin(),inorder.end());
        unordered_map<int,int> mp = populateMap(inorder);
        int preIndex = 0;
        return constructTree(preorder,mp,0,inorder.size()-1,preIndex);
    }
};