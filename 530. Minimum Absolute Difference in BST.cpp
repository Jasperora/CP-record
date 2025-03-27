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
        int prev = -1;
        int ret = INT_MAX;
        void search(TreeNode* node){
            if(!node) return;
            search(node->left);
            if(prev!=-1) ret = min(ret, abs(prev-node->val));
            prev = node->val;
            search(node->right);
        }
        int getMinimumDifference(TreeNode* root) {
            search(root);
            return ret;
        }
    };