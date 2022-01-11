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
    int sumRootToLeaf(TreeNode* rt,int val=0) {
           if(! rt) return 0;
        
        int ans = 0;
        stack<pair<TreeNode*,int>> st;
        st.push({rt,0});
        
        while(! st.empty()) {
            auto curp = st.top(); st.pop();
            TreeNode* cur = curp.first;
            int cur_val = curp.second;
            
            // Equivalent to left shift by 1 and then ORing by cur->val.
            cur_val = cur_val*2 + cur->val;
            
            if(!cur->left && !cur->right)
                ans += cur_val;
            
            if(cur->left) st.push({cur->left, cur_val});
            if(cur->right) st.push({cur->right, cur_val});
        }
        
        return ans;
        
        
        
    }
    
};