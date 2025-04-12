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
        unordered_map<int, int> root_idx;
        int n;
        TreeNode* build(const vector<int>& preorder, int pre_start, int in_start, int in_end){
            if(pre_start >= n || in_start > in_end) return nullptr;
            TreeNode* root = new TreeNode(preorder[pre_start]);
            int idx = root_idx[preorder[pre_start]];
            root->left = build(preorder, pre_start + 1, in_start, idx - 1);
            int leftTreeSize = idx - in_start;
            root->right = build(preorder, pre_start + leftTreeSize + 1, idx + 1, in_end);
            return root;
        }
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            n = preorder.size();
            for(int i = 0; i < n; ++i){
                root_idx[inorder[i]] = i;
            }
            return build(preorder, 0, 0, n-1);
        }
    };