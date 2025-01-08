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
    queue<TreeNode*> q;
    void invert(){
        if(q.empty()) return;
        vector<TreeNode*> next_level;
        while(!q.empty()){
            TreeNode* tmp = q.front()->left;
            q.front()->left = q.front()->right;
            q.front()->right = tmp;
            if(q.front()->left) next_level.push_back(q.front()->left);
            if(q.front()->right) next_level.push_back(q.front()->right);
            q.pop();
        }
        for(auto& node : next_level) q.push(node);
        invert();
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr) return root;
        q.push(root);
        invert();
        return root;
    }
};
