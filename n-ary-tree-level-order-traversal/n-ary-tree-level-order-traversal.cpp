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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;        
        queue<Node*>q;
        q.push(root);        
        while(q.size()){
            int size=q.size();
            
            vector<int>level;
            while(size--){
                auto a=q.front();
                q.pop();
                level.push_back(a->val);
                  for(auto c:a->children){
                      q.push(c);
                  }
            }
          ans.push_back(level);
        }
        return ans;
    }
};