/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int>ans;
        stack<Node*> st;
        
        if(root == NULL)return ans;
        st.push(root);
        
        while(!st.empty()){
            Node *currentNode = root;
            currentNode = st.top();
            st.pop();
            ans.push_back(currentNode->val);
            
            vector<Node*> childrens = currentNode->children;
            int n = childrens.size();
            
            for(int i = 0;i< n;i++){
                st.push(childrens[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};