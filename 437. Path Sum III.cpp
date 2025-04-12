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
#define ll unsigned long long
class Solution {
public:
    unordered_map<ll, int> presumCnt;
    int dfs(TreeNode* node, ll curSum, const int& targetSum){
        if(!node) return 0;
        curSum += node->val;

        // curSum - x = targetSum
        // x = curSum - targetSum, so check presumCnt[curSum - targetSum]
        int numPathsToCur = presumCnt[curSum - targetSum];
        ++presumCnt[curSum];
        numPathsToCur += dfs(node->left, curSum, targetSum);
        numPathsToCur += dfs(node->right, curSum, targetSum);
        --presumCnt[curSum];
        return numPathsToCur;
    }
    int pathSum(TreeNode* root, int targetSum) {
        presumCnt[0] = 1;
        return dfs(root, 0, targetSum);
    }
};