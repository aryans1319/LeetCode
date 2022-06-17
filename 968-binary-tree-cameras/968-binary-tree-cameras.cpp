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
private:
    int count;
    void __init__(){
        count = 0;
    }
    
    int postOrder(TreeNode* root){
        // null will return need a camera
        if(!root){
            return 1;
        }
        //bottom most will always need a camera
        if(!root->left and !root->right){
            return -1;
        }
        
        int left = postOrder(root->left);
        int right = postOrder(root->right);
        
        // if any of the childs need a camera, then get a camera
        // and return that you have a camera
        if(left == -1 or right == -1){
            count++;
            return 0;
        }
        // if any of the child return that they have a camera
        // return that you do not need a camera
        else if(left == 0 or right == 0){
            return 1;
        }
        // if both the child are covered
        // then request your parent to cover you
        else if(left == 1 and right == 1){
            return -1;
        }
        return -1;
    }
public:
    int minCameraCover(TreeNode* root) {
        __init__();
        // the root needs is a special case, image that only one node is there
        int root_needs = postOrder(root);
        return root_needs==-1? count+1 : count;
    }
};