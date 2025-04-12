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
        unordered_map<string, int> treeCnt;
        vector<TreeNode*> ans;
        string serialize(TreeNode* node){
            if(!node) return "#";
            string ret = "";
            ret += to_string(node->val);
            ret.push_back(',');
            ret += serialize(node->left);
            ret.push_back(',');
            ret += serialize(node->right);
            if(treeCnt[ret] == 1) ans.push_back(node);
            ++treeCnt[ret];
            return ret;
        }
        vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
            serialize(root);
            return ans;
        }
    };