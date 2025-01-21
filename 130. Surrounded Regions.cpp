class Solution {
public:
    int m, n;
    vector<vector<bool> > visited;
    void dfs(int i, int j, vector<vector<bool> >& visited, vector<vector<char> >& board){
        if(i<0||j<0||i==m||j==n||visited[i][j]||board[i][j]=='X') return;
        visited[i][j] = true;
        dfs(i+1, j, visited, board);
        dfs(i-1, j, visited, board);
        dfs(i, j+1, visited, board);
        dfs(i, j-1, visited, board);
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        visited.resize(m);
        for(int i = 0; i < m; ++i){
            visited[i].resize(n, false);
        }
        for(int i = 0; i < m; ++i){
            if(board[i][0]=='O') dfs(i, 0, visited, board);
            if(board[i][n-1]=='O') dfs(i, n-1, visited, board);
        }
        for(int i = 0; i < n; ++i){
            if(board[0][i]=='O') dfs(0, i, visited, board);
            if(board[m-1][i]=='O') dfs(m-1, i, visited, board);
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(!visited[i][j]) board[i][j] = 'X';
            }
        }
    }
};
