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
    bool isSame(TreeNode* root_a, TreeNode* root_b){
        if(root_a==root_b&&!root_a) return true;
        else if((!root_a&&root_b)||(root_a&&!root_b)) return false;
        else{
            if((root_a->left&&!root_b->left)||(!root_a->left&&root_b->left)) return false;
            if((root_a->right&&!root_b->right)||(!root_a->right&&root_b->right)) return false;
            bool same = true;
            same &= root_a->val==root_b->val;
            if(root_a->left)
                same &= isSame(root_a->left, root_b->left);
            if(root_a->right)
                same &= isSame(root_a->right, root_b->right);
            return same;
        }
    }
    bool Traversal(TreeNode* root, TreeNode* subRoot){
        if(isSame(root, subRoot)){
            return true;
        }else if(!root){
            return false;
        }else{
            return Traversal(root->left, subRoot) || Traversal(root->right, subRoot);
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // if(!root&&!subRoot) return true;
        // if((!root&&subRoot)||(root&&!subRoot)) return false;
        return Traversal(root, subRoot);
        
    }
};
