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
    void addToVector(TreeNode* root){
        if(root!=nullptr){
            addToVector(root->left);
            ret.push_back(root->val);
            addToVector(root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        addToVector(root);
        return ret;
        
    }
};