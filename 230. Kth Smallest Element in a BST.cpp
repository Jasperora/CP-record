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
        int cnt;
        int search(TreeNode* node){
            if(!node) return 0;
            int left = search(node->left);
            if(cnt==0) return left;
            cnt--;
            if(cnt==0) return node->val;
            return search(node->right);
        }
        int kthSmallest(TreeNode* root, int k) {
            cnt = k;
            return search(root);
        }
    };