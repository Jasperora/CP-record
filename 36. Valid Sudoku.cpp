class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, int> row_cnt[9];
        map<int, int> col_cnt[9];
        map<int, int> sub_box_cnt[9];
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j]!='.'){
                    if(!row_cnt[i].count(board[i][j])) row_cnt[i][board[i][j]] = 0;
                    if(!col_cnt[j].count(board[i][j])) col_cnt[j][board[i][j]] = 0;
                    ++row_cnt[i][board[i][j]];
                    ++col_cnt[j][board[i][j]];
                    int sub_box_idx;
                    sub_box_idx = (i-(i%3)) + (j-(j%3))/3;
                    if(!sub_box_cnt[sub_box_idx].count(board[i][j]))
                        sub_box_cnt[sub_box_idx][board[i][j]] = 0;
                    ++sub_box_cnt[sub_box_idx][board[i][j]];
                }
            }
        }
        bool ans = true;
        for(int i = 0; i < 9; ++i){
            for(auto& p : row_cnt[i]) ans &= (p.second<2);
            for(auto& p : col_cnt[i]) ans &= (p.second<2);
            for(auto& p : sub_box_cnt[i]) ans &= (p.second<2);
        }
        return ans;
    }
};