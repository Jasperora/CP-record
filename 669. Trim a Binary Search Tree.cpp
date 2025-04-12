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
        TreeNode* Trim(TreeNode* node, const int& low, const int& high){
            if(!node) return nullptr;
            TreeNode* left = Trim(node->left, low, high);
            TreeNode* right = Trim(node->right, low, high);
    
            if(node->val < low || node->val > high){
                return left ? left : right;
            }else{
                node->left = left;
                node->right = right;
            }
            return node;
        }
        TreeNode* trimBST(TreeNode* root, int low, int high) {
            return Trim(root, low, high);
        }
    };