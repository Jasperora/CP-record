class TrieNode {
public:
    bool is_end;
    TrieNode* children[26];
    TrieNode(){
        is_end = false;
        for(int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};
class Solution {
public:
    vector<vector<bool>> visited;
    vector<string> ret;
    unordered_set<string> counted;
    string cur;
    int m, n;
    void dfs(const vector<vector<char>>& board, TrieNode* node, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j]) return;
        visited[i][j] = true;
        if(node->children[board[i][j]-'a']){
            cur.push_back(board[i][j]);
            node = node->children[board[i][j]-'a'];
            if(node->is_end && !counted.count(cur)){
                ret.push_back(cur);
                counted.insert(cur);
            }
            dfs(board, node, i+1, j);
            dfs(board, node, i-1, j);
            dfs(board, node, i, j+1);
            dfs(board, node, i, j-1);
            cur.pop_back();
        }
        visited[i][j] = false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // add all words to trie
        // use dfs starting from each grid to check
        TrieNode* root = new TrieNode();
        for(auto& word : words){
            TrieNode* cur = root;
            for(auto& c : word){
                if(!cur->children[c-'a']){
                    TrieNode* newTrieNode = new TrieNode();
                    cur->children[c-'a'] = newTrieNode;
                }
                cur = cur->children[c-'a'];
            }
            cur->is_end = true;
        }
        m = board.size();
        n = board[0].size();
        visited.resize(m, vector<bool>(n, false));
        cur = "";
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                dfs(board, root, i, j);
            }
        }
        return ret;
    }
};