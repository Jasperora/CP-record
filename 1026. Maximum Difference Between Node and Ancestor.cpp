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
        int dfs(TreeNode* node, int curMax, int curMin){
            if(!node) return 0;
            curMax = max(curMax, node->val);
            curMin = min(curMin, node->val);
            int ret = curMax - curMin;
            ret = max(ret, dfs(node->left, curMax, curMin));
            ret = max(ret, dfs(node->right, curMax, curMin));
            return ret;
        }
        int maxAncestorDiff(TreeNode* root) {
            return dfs(root, INT_MIN, INT_MAX);
        }
    };