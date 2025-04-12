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
class BSTIterator {
    public:
        vector<int> nums;
        int ptr;
        stack<TreeNode*> st;
        BSTIterator(TreeNode* root) {
            st.push(root);
            while(!st.empty()){
                TreeNode* top = st.top();
                if(top->left) st.push(top->right);
                if()
            }
            ptr = 0;
        }
        
        int next() {
            return nums[ptr++];
        }
        
        bool hasNext() {
            return ptr < nums.size();
        }
    };
    
    /**
     * Your BSTIterator object will be instantiated and called as such:
     * BSTIterator* obj = new BSTIterator(root);
     * int param_1 = obj->next();
     * bool param_2 = obj->hasNext();
     */