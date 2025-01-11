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
    vector<int> elements;
    void dfs(TreeNode* root, int& k){
        if(!root) return;
        dfs(root->left, k);
        elements.push_back(root->val);
        if(elements.size()==k) return;
        dfs(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return elements[k-1];
    }
};
