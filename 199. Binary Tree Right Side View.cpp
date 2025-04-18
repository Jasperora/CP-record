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
        vector<int> ret;
        void search(TreeNode* node, int level){
            if(!node) return;
            if(level == ret.size()) ret.push_back(node->val);
    
            search(node->right, level+1);
            search(node->left, level+1);
        }
        vector<int> rightSideView(TreeNode* root) {
            search(root, 0);
            return ret;
        }
    };