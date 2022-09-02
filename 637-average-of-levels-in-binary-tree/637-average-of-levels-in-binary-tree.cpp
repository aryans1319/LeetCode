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
    double findAverage(vector<double> &nums){
        double sum = 0;
        double n = nums.size();
        for(auto i : nums){
            sum += i;
        }
        return (double)(sum/n);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>temp;
        queue<TreeNode *> q;
        q.push(root);
        if(root == NULL) return temp;
        while(!q.empty()){
            double ans = 0;
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode *node = q.front();
                q.pop();
                // temp.push_back(node->val);
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
                ans += node->val;                
            }
            temp.push_back((double)(ans/size));
        }
       
        return temp;
    }
};