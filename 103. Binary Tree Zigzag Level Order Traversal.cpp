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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            if(!root) return {};
            vector<vector<int>> ret;
            deque<TreeNode*> dq;
            dq.push_front(root);
            bool order = true;
            while(!dq.empty()){
                int n = dq.size();
                vector<int> level;
                for(int i = 0; i < n; ++i){
                    if(order){
                        level.push_back(dq.front()->val);
                        if(dq.front()->left) dq.push_back(dq.front()->left);
                        if(dq.front()->right) dq.push_back(dq.front()->right);
                        dq.pop_front();
    
                    }else{
                        level.push_back(dq.back()->val);
                        if(dq.back()->right) dq.push_front(dq.back()->right);
                        if(dq.back()->left) dq.push_front(dq.back()->left);
                        dq.pop_back();
                    }
                }
                order ^= 1;
                ret.push_back(level);
            }
            return ret;
        }
    };