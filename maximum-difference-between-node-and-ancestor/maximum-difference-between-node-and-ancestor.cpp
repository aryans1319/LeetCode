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
 int maxAncestorDiff(TreeNode* r, int mn = 100000, int mx = 0) {
  if (r == nullptr) return mx - mn;
  mx = max(mx, r->val);
  mn = min(mn, r->val);
  return max(maxAncestorDiff(r->left, mn, mx), maxAncestorDiff(r->right, mn, mx));
}
};