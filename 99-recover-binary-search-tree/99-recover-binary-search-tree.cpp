class Solution {
public:
    void inor(TreeNode*&root,vector<TreeNode*>&v){
        if(root==nullptr)return;
        inor(root->left,v);
        v.push_back(root);
        inor(root->right,v);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*>inorder;
        inor(root,inorder);
        int first=-1,second=-1,third=-1;
        for(int i=0;i<inorder.size()-1;i++){
            if(inorder[i]->val>inorder[i+1]->val){
                if(first==-1&&second==-1){
                first=i;
                second=i+1;
                }
                else{third=i+1;}
            }
        }
            if(third==-1){
                int temp=inorder[first]->val;
                inorder[first]->val=inorder[second]->val;
                inorder[second]->val=temp;
            }
            else{
                 int temp=inorder[first]->val;
                inorder[first]->val=inorder[third]->val;
                inorder[third]->val=temp;
                }
             }
};