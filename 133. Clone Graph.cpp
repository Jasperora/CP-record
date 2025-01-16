class Solution {
public:
    vector<vector<bool> > visited;
    bool ret = false;
    int m, n;
    void search(int i, int j, int idx, const vector<vector<char> >& board, const string& word){
        if(board[i][j]==word[idx]){
            visited[i][j] = true;
            ++idx;
            if(idx==word.size()){
                ret = true;
                return;
            }
            // for(int i = 0; i < m; ++i){
            //     for(int j = 0; j < n; ++j)
            //         cout << visited[i][j] << ' ';
            //     cout << '\n';
            // }
            // cout << "===========\n";
            vector<pair<int, int> > neighbors;
            if(i!=0&&!visited[i-1][j]) neighbors.push_back({i-1, j});
            if(i!=board.size()-1&&!visited[i+1][j]) neighbors.push_back({i+1, j});
            if(j!=0&&!visited[i][j-1]) neighbors.push_back({i, j-1});
            if(j!=board[0].size()-1&&!visited[i][j+1]) neighbors.push_back({i, j+1});
            for(auto& p : neighbors){
                search(p.first, p.second, idx, board, word);
                visited[p.first][p.second] = false;
            }
            visited[i][j] = false;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        visited = vector<vector<bool> >(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                search(i, j, 0, board, word);
            }
        }
        return ret;
    }
};
