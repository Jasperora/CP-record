/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// dfs: preorder traversal
class Codec1 {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }
    int i = 0;
    TreeNode* dfs(const vector<TreeNode*>& nodes){
        if(i >= nodes.size()) return nullptr;
        if(!nodes[i]){
            ++i;
            return nullptr;
        }
        TreeNode* ret = new TreeNode(nodes[i]->val);
        ++i;
        ret->left = dfs(nodes);
        ret->right = dfs(nodes);
        return ret;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> nodes;
        string cur = "";
        for(int i = 0; i < data.size(); ++i){
            if(data[i] != ','){
                cur.push_back(data[i]);
            }else{
                if(cur != "#"){
                    nodes.push_back(new TreeNode(stoi(cur)));
                }else{
                    nodes.push_back(nullptr);
                }
                cur = "";
            }
        }
        return dfs(nodes);
    }
};
// bfs: level order traversal
class Codec2 {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string ret = "";
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(!node) ret += "#,";
            else{
                ret += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> nodes;
        string cur = "";
        for(int i = 0; i < data.size(); ++i){
            if(data[i] != ',') cur.push_back(data[i]);
            else{
                if(cur == "#") nodes.push_back(nullptr);
                else nodes.push_back(new TreeNode(stoi(cur)));
                cur = "";
            }
        }
        int i = 0, j = 1;
        int n = nodes.size();
        while(i < n){
            if(nodes[i]){
                if(j+1 < n){
                    nodes[i]->left = nodes[j];
                    nodes[i]->right = nodes[j+1];
                }
                j += 2;
            }
            ++i;
        }
        return nodes[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));