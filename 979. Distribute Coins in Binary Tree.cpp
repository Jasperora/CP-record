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
        int ret = 0;
        int cal(TreeNode* root){
            if(!root) return 0;
            int leftExcess = cal(root->left);
            int rightExcess = cal(root->right);
            // -1 because root node needs a coin
            // need to minus excess by 1
            ret += abs(leftExcess) + abs(rightExcess);
            return root->val + leftExcess + rightExcess - 1;
        }
        int distributeCoins(TreeNode* root) {
            cal(root);
            return ret;
        }
    };