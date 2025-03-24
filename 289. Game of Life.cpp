class Solution {
    public:
        void gameOfLife(vector<vector<int>>& board) {
            int m = board.size(), n = board[0].size();
            vector<vector<int>> alive_neighbors(m, vector<int>(n, 0));
            vector<pair<int, int>> dirs(8);
            dirs[0] = {-1, 0};
            dirs[1] = {1, 0};
            dirs[2] = {0, 1};
            dirs[3] = {0, -1};
            dirs[4] = {1, -1};
            dirs[5] = {-1, 1};
            dirs[6] = {1, 1};
            dirs[7] = {-1, -1};
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    int cnt = 0;
                    for(int k = 0; k < 8; ++k){
                        int new_i = i+dirs[k].first;
                        int new_j = j+dirs[k].second;
                        if(new_i>=0 && new_i<m && new_j>=0 && new_j < n){
                            if(board[new_i][new_j]) ++cnt;
                        }
                    }
                    alive_neighbors[i][j] = cnt;
                }
            }
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    int a = board[i][j], b = alive_neighbors[i][j];
                    if(a==1){
                        if(b<2 || b>3) board[i][j] = 0;
                    }else{
                        if(b==3) board[i][j] = 1;
                    }
                }
            }
            return;
        }
    };