/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        unordered_map<TreeNode*, TreeNode*> parentMap;
        void createParentMap(TreeNode* root){
            if(!root) return;
            if(root->left){
                parentMap[root->left] = root;
                createParentMap(root->left);
            }
            if(root->right){
                parentMap[root->right] = root;
                createParentMap(root->right);
            }
        }
        vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            parentMap[root] = nullptr;
            createParentMap(root);
            vector<int> ret;
            queue<TreeNode*> q;
            q.push(target);
            int distance = 0;
            unordered_set<TreeNode*> visited;
            visited.insert(target);
            while(!q.empty()){
                int len = q.size();
                if(distance == k){
                    for(int i = 0; i < len; ++i){
                        ret.push_back(q.front()->val);
                        q.pop();
                    }
                    return ret;
                }
                for(int i = 0; i < len; ++i){
                    TreeNode* front = q.front();
                    visited.insert(front);
                    if(parentMap.count(front) && parentMap[front] && !visited.count(parentMap[front])){
                        q.push(parentMap[front]);
                    }
                    if(front->left && !visited.count(front->left)) q.push(front->left);
                    if(front->right && !visited.count(front->right)) q.push(front->right);
                    q.pop();
                }
                
                ++distance;
            }
            return {};
        }
    };