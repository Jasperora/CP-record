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
        vector<int> nums;
        void search(TreeNode* node){
            if(!node) return;
            search(node->left);
            nums.push_back(node->val);
            search(node->right);
        }
        int minDiffInBST(TreeNode* root) {
            int ret = 2e6;
            search(root);
            for(int i = 0; i < nums.size()-1; ++i){
                int diff = nums[i+1]-nums[i];
                ret = min(ret, diff);
            }
            return ret;
        }
    };