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
#define ll unsigned long long
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 1});
        ll ret = 0;
        while(!q.empty()){
            int n = q.size();
            ll mn = q.front().second;
            ll mx = q.back().second;
            for(int i = 0; i < n; ++i){
                pair<TreeNode*, ll> p = q.front();
                q.pop();
                if(p.first->left) q.push({p.first->left, p.second * 2});
                if(p.first->right) q.push({p.first->right, p.second * 2 + 1});
            }
            ret = max(ret, mx - mn + 1);
        }
        return (int)ret;
    }
};