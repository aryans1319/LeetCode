/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void populateMap(TreeNode* currentNode,TreeNode *currentParent,unordered_map<TreeNode*,TreeNode*>&parentMap){
        if(currentNode == NULL) return;
        parentMap[currentNode] = currentParent;
        populateMap(currentNode->left,currentNode,parentMap);
        populateMap(currentNode->right,currentNode,parentMap);
        return;
    }
    
    void printKDistance(TreeNode* currentNode,int k,set<TreeNode*>&st,unordered_map<TreeNode*,TreeNode*>&parentMap,vector<int>&ans){
        if(currentNode == NULL || st.find(currentNode)!=st.end() || k<0){
            return;
        }
        
        st.insert(currentNode);
        if(k==0){
            ans.push_back(currentNode->val);
            return;
        }
        printKDistance(currentNode->left,k-1,st,parentMap,ans);
         printKDistance(currentNode->right,k-1,st,parentMap,ans);
         printKDistance(parentMap[currentNode],k-1,st,parentMap,ans);
        return;
        
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        set<TreeNode*>st;
        unordered_map<TreeNode*,TreeNode*> parentMap;
        populateMap(root,NULL,parentMap);
        printKDistance(target,k,st,parentMap,ans);
        return ans;
    }
};