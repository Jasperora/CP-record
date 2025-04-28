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
class Solution1 {
public:
    // dp[node] = {rob cur max, not rob cur max}
    unordered_map<TreeNode*, pair<int, int>> dp;
    pair<int, int> dfs(TreeNode* node){
        if(!node)
            return {0, 0};
        if(dp.count(node))
            return dp[node];
        
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        int rob_current = node->val + left.second + right.second;
        int not_rob_current = max(left.first, left.second) + max(right.first, right.second);
        return {rob_current, not_rob_current};
    }
    int rob(TreeNode* root) {
        auto p = dfs(root);
        return max(p.first, p.second);
    }
};
class Solution2 {
public:
    map<pair<TreeNode*, bool>, int> dp;
    int dfs(TreeNode* node, bool has_stolen){
        if(!node) return 0;
        if(dp.count({node, has_stolen}))
            return dp[{node, has_stolen}];

        if(has_stolen){
            // cannot steal current node
            int left = 0, right = 0;
            left = dfs(node->left, false);
            right = dfs(node->right, false);
            return dp[{node, true}] = left + right;
        }else{
            // steal current node
            int steal_left, steal_right;
            steal_left = dfs(node->left, true);
            steal_right = dfs(node->right, true);
            // not steal current node
            int not_steal_left, not_steal_right;
            not_steal_left = dfs(node->left, false);
            not_steal_right = dfs(node->right, false);
            int mx = steal_left + steal_right + node->val;
            mx = max(mx, not_steal_left + not_steal_right);
            return dp[{node, false}] = mx;
        }
    }
    int rob(TreeNode* root) {
        return max(dfs(root, false), dfs(root, true));
    }
};