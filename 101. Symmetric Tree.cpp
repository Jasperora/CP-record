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
        bool isSymmetric(TreeNode* root) {
            if(!root || (!root->left&&!root->right)) return true;
            if(!root->left || !root->right) return false;
            queue<pair<TreeNode*, TreeNode*>> q;
            q.push({root->left, root->right});
            while(!q.empty()){
                pair<TreeNode*, TreeNode*> p = q.front();
                q.pop();
                if(!p.first && !p.second) continue;
                if(!p.first || !p.second || p.first->val!=p.second->val) return false;
                q.push({p.first->left, p.second->right});
                q.push({p.first->right, p.second->left});
            }
            return true;
        }
        bool isSymmetric2(TreeNode* root) {
            if(!root) return true;
            return isMirror(root->left, root->right);
        }
        bool isMirror(TreeNode* a, TreeNode* b){
            if(!a && !b) return true;
            if(!a || !b) return false;
            return a->val==b->val && isMirror(a->left, b->right) && isMirror(a->right, b->left);
        }
    };