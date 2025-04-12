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
        // inorder: leftSubTree -> root -> rightSubTree
        // postorder: leftSubTree -> rightSubTree -> root
        TreeNode* build(vector<int>& postorder, int post_start, int in_start, int in_end){
            if(post_start < 0 || in_start > in_end) return nullptr;
            int root_val = postorder[post_start];
            TreeNode* root = new TreeNode(root_val);
            int idx = root_idx[root_val];
            root->right = build(postorder, post_start - 1, idx + 1, in_end);
            int rightSubTreeSize = in_end - idx;
            root->left = build(postorder, post_start - rightSubTreeSize - 1, in_start, idx - 1);
            return root;
        }
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            int n = inorder.size();
            for(int i = 0; i < n; ++i){
                root_idx[inorder[i]] = i;
            }
            return build(postorder, n-1, 0, n-1);
        }
    };