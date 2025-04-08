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
        vector<vector<int>> levelOrder(TreeNode* root) {
            if(!root) return {};
            queue<TreeNode*> q;
            vector<vector<int>> ret;
            q.push(root);
            while(!q.empty()){
                int n = q.size();
                vector<int> curLevel(n);
                for(int i = 0; i < n; ++i){
                    curLevel[i] = q.front()->val;
                    if(q.front()->left) q.push(q.front()->left);
                    if(q.front()->right) q.push(q.front()->right);
                    q.pop();
                }
                ret.push_back(curLevel);
            }
            return ret;
        }
    };