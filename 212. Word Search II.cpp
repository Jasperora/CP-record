class TrieNode{
public:
    bool is_end;
    TrieNode* children[26];

    TrieNode(){
        for(int i = 0; i < 26; ++i){
            children[i] = nullptr;
        }
        is_end = false;
    }

    void insert(string word){
        TrieNode* cur = this;
        for(auto& c : word){
            int i = c-'a';
            if(cur->children[i]==nullptr){
                cur->children[i] = new TrieNode();
            }
            cur = cur->children[i];
        }
        cur->is_end = true;
    }
};

class Solution {
private:
    vector<vector<bool> > visit;
    vector<string> ret;
    int n_row, n_col;
    void dfs(vector<vector<char> >& board, int r, int c, TrieNode* node, string word){
        if(r<0||c<0||r==n_row||c==n_col||visit[r][c]||!node->children[board[r][c]-'a'])
            return;
        visit[r][c] = true;
        word.push_back(board[r][c]);
        node = node->children[board[r][c]-'a'];
        if(node->is_end){
            ret.push_back(word);
            node->is_end = false;
        }
        dfs(board, r-1, c, node, word);
        dfs(board, r+1, c, node, word);
        dfs(board, r, c-1, node, word);
        dfs(board, r, c+1, node, word);
        visit[r][c] = false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode root;
        for(auto& word : words){
            root.insert(word);
        }
        n_row = board.size();
        n_col = board[0].size();
        visit.resize(n_row, vector<bool>(n_col, false));
        for(int i = 0; i < n_row; ++i){
            for(int j = 0; j < n_col; ++j){
                dfs(board, i, j, &root, "");
            }
        }
        return ret;
    }
};
