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
        TreeNode* flat(TreeNode* root){
            if(!root) return nullptr;
            TreeNode* leftSubTree = flat(root->left);
            TreeNode* rightSubTree = flat(root->right);
            root->left = nullptr;
            root->right = leftSubTree;
            TreeNode* cur = leftSubTree;
            while(cur && cur->right){
                cur = cur->right;
            }
            if(cur)
                cur->right = rightSubTree;
            else
                root->right = rightSubTree;
            return root;
        }
        void flatten(TreeNode* root) {
            flat(root);
        }
    };