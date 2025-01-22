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

class Codec {
private:
    int i = 0;
    vector<string> split(const string& data, const char& delim){
        vector<string> ret;
        string s = "";
        for(auto&c : data){
            if(c==delim){
                ret.push_back(s);
                s = "";
            }else{
                s.push_back(c);
            }
        }
        return ret;
    }
    TreeNode* dfs(vector<string>& v){
        if(v[i]=="N"){
            ++i;
            return nullptr;
        }
        TreeNode* ret = new TreeNode(stoi(v[i]));
        ++i;
        ret->left = dfs(v);
        ret->right = dfs(v);
        return ret;
    }
public:

    // Encodes a tree to a single string.
    string ret = "";
    string serialize(TreeNode* root) {
        if(!root) return "N,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v = split(data, ',');
        return dfs(v);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));