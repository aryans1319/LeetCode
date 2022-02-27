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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        queue<pair<TreeNode*, string>> bfs;
        bfs.push({root, to_string(root->val)});
        bfs.push({NULL, ""});
        while (!bfs.empty()) {
            auto currNode = bfs.front();
            bfs.pop();
            if (currNode.first) {
                auto currPath = currNode.second;
                if (!currNode.first->left and !currNode.first->right)
                    paths.push_back(currPath);
                else {
                    if (currNode.first->left)
                        bfs.push({currNode.first->left, currPath + "->" + to_string(currNode.first->left->val)});
                    if (currNode.first->right)
                        bfs.push({currNode.first->right, currPath + "->" + to_string(currNode.first->right->val)});
                }
            }
            else if (!bfs.empty())
                bfs.push({NULL, ""});
        }
        return paths;
    }
};