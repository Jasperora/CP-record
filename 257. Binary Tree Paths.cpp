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
        vector<string> ret;
        vector<int> path;
        void dfs(TreeNode* node){
            if(!node) return;
            if(!node->left && !node->right){
                path.push_back(node->val);
                string s = "";
                for(int i = 0; i < path.size()-1; ++i){
                    s += to_string(path[i]);
                    s += "->";
                }
                s += to_string(path.back());
                ret.push_back(s);
            }else{
                path.push_back(node->val);
            }
            dfs(node->left);
            dfs(node->right);
            path.pop_back();
        }
        vector<string> binaryTreePaths(TreeNode* root) {
            dfs(root);
            return ret;
        }
    };