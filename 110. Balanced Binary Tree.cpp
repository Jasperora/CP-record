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
    int Height(TreeNode* root){
        int height = 0;
        if(root->left) height = max(height, 1+Height(root->left));
        if(root->right) height = max(height, 1+Height(root->right));
        return height;
    }
    bool recursiveIsBalanced(TreeNode* root){
        if(!root->left&&!root->right) return true;
        else if(!root->left||!root->right){
            if(!root->left)
                return Height(root->right) == 0;
            else return Height(root->left) == 0;
        }else{
            return abs(Height(root->left)-Height(root->right)) <= 1 && recursiveIsBalanced(root->left) && recursiveIsBalanced(root->right);
        }
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return recursiveIsBalanced(root);
    }
};
