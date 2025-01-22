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
    int ret = -1001;
    map<TreeNode*, int> dp;
    int maxRouteSum(TreeNode* root){
        if(!root) return 0;
        if(dp.count(root)) return dp[root];
        if(!root->left&&!root->right){
            dp[root] = root->val;
            ret = max(ret, dp[root]);
            return dp[root];
        }
        dp[root] = root->val + max(max(maxRouteSum(root->left), maxRouteSum(root->right)), 0);
        ret = max(ret, max(dp[root], root->val+maxRouteSum(root->left)+maxRouteSum(root->right)));
        return dp[root];
    }
    int maxPathSum(TreeNode* root) {
        maxRouteSum(root);
        return ret;
    }
};
