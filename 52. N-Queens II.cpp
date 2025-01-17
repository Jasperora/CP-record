class Solution {
public:
    int ret = 0;
    vector<pair<int, int> > queen_pos;
    void backtrack(int row, const int& n){
        if(row==n){
            ++ret;
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
                    queen_pos.push_back({row, j});
                    backtrack(row+1, n);
                    queen_pos.pop_back();
                }
            }
        }
    }
    int totalNQueens(int n) {
        backtrack(0, n);
        return ret;
    }
};