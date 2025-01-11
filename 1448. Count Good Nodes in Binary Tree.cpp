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
    void search(TreeNode* root, int lower_bound){
        if(!root) return;
        if(root->val>=lower_bound){
            ++ret;
            lower_bound = root->val;
        }
        if(root->left) search(root->left, lower_bound);
        if(root->right) search(root->right, lower_bound);
    }
    int goodNodes(TreeNode* root) {
        search(root, -10001);
        return ret;
    }
};
