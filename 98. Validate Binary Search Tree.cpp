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
    bool ret = true;
    void search(long long lower_bound, long long upper_bound, TreeNode* root){
        if(!root) return;
        if((long long)root->val<=lower_bound||(long long)root->val>=upper_bound){
            ret = false;
        }else{
            if(root->left) search(lower_bound, min((long long)root->val, upper_bound), root->left);
            if(root->right) search(max((long long)root->val, lower_bound), upper_bound, root->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        search(-2147483649, 2147483648, root);
        return ret;
    }
};
