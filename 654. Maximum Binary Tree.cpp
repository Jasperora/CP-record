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
        TreeNode* build(vector<int>& nums, int i, int j){
            if(i==j){
                TreeNode* t = new TreeNode(nums[i]);
                return t;
            }else if(i>j) return nullptr;
            int mx = -1, mxIdx;
            for(int k = i; k <= j; ++k){
                if(nums[k]>mx){
                    mx = nums[k];
                    mxIdx = k;
                }
            }
            TreeNode* t = new TreeNode(nums[mxIdx]);
            t->left = build(nums, i, mxIdx-1);
            t->right = build(nums, mxIdx+1, j);
            return t;
        }
        TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
            return build(nums, 0, nums.size()-1);
        }
    };