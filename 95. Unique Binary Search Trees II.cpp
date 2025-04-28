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
// dfs + memoization
class Solution1 {
public:
    unordered_map<string, vector<TreeNode*>> dp;
    vector<TreeNode*> dfs(int start, int end){
        if(start > end) return {nullptr};
        if(start == end) return {new TreeNode(start)};
        string st = to_string(start) + "-" + to_string(end);
        if(dp.count(st))
            return dp[st];
        vector<TreeNode*> ret;
        for(int root = start; root <= end; ++root){
            vector<TreeNode*> leftSubtrees = dfs(start, root - 1);
            vector<TreeNode*> rightSubtrees = dfs(root + 1, end);
            for(auto& left: leftSubtrees){
                for(auto& right: rightSubtrees){
                    TreeNode* node = new TreeNode(root);
                    node->left = left;
                    node->right = right;
                    ret.push_back(node);
                }
            }
        }
        return dp[st] = ret;
    }
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }
};
// brute force dfs
class Solution2 {
public:
    vector<TreeNode*> dfs(int start, int end){
        if(start > end) return {nullptr};
        if(start == end) return {new TreeNode(start)};
        vector<TreeNode*> ret;
        for(int root = start; root <= end; ++root){
            vector<TreeNode*> leftSubtrees = dfs(start, root - 1);
            vector<TreeNode*> rightSubtrees = dfs(root + 1, end);
            for(auto& left: leftSubtrees){
                for(auto& right: rightSubtrees){
                    TreeNode* node = new TreeNode(root);
                    node->left = left;
                    node->right = right;
                    ret.push_back(node);
                }
            }
        }
        return ret;
    }
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }
};