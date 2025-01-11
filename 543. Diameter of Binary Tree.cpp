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
    int Height(TreeNode* root){
        int left_height = 0, right_height = 0;
        if(root->left) left_height = 1+Height(root->left);
        if(root->right) right_height = 1+Height(root->right);
        ret = max(ret, left_height+right_height);
        return max(left_height, right_height);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        Height(root);
        return ret;
    }
};
