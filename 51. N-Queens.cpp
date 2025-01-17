class Solution {
public:
    vector<vector<string> > ret;
    vector<string> board;
    vector<pair<int, int> > queen_pos;
    void backtrack(int row, const int& n){
        if(row==n){
            // for(int i = 0; i < n; ++i){
            //     for(int j = 0; j < n; ++j){
            //         cout << board[i][j] << ' ';
            //     }
            //     cout << '\n';
            // }
            // cout << "==========\n";
            ret.push_back(board);
        }else{
            for(int j = 0; j < n; ++j){
                bool can_place = true;
                for(auto& p : queen_pos){
                    if(abs(p.first-row)==abs(p.second-j)||j==p.second){
                        can_place = false;
                        break;
                    }
                }
                if(can_place){
                    string r = "";
                    for(int k = 0; k < n; ++k)
                        r.push_back('.');
                    r[j] = 'Q';
                    board.push_back(r);
                    queen_pos.push_back({row, j});
                    backtrack(row+1, n);
                    board.pop_back();
                    queen_pos.pop_back();
                }
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        backtrack(0, n);
        return ret;
    }
};
