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
    int ret = 0;
    void search(){
        if(q.empty()) return;
        ++ret;
        vector<TreeNode*> next_level;
        while(!q.empty()){
            if(q.front()->left!=nullptr)
                next_level.push_back(q.front()->left);
            if(q.front()->right!=nullptr)
                next_level.push_back(q.front()->right);
            q.pop();
        }
        for(auto& node : next_level)
            q.push(node);
        search();
    }
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        q.push(root);
        search();
        return ret;
    }
};