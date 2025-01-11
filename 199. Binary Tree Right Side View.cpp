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
    queue<TreeNode*> q;
    void search(){
        if(q.empty()) return;
        vector<int> level;
        vector<TreeNode*> next_level;
        while(!q.empty()){
            level.push_back(q.front()->val);
            if(q.front()->left) next_level.push_back(q.front()->left);
            if(q.front()->right) next_level.push_back(q.front()->right);
            q.pop();
        }
        ret.push_back(level[level.size()-1]);
        for(auto& node : next_level){
            q.push(node);
        }
        search();

    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return ret;
        q.push(root);
        search();
        return ret;
    }
};
