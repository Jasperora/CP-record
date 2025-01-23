class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> cnt_row(m, 0);
        vector<int> cnt_col(n, 0);
        int ret = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j]==1){
                    ++cnt_row[i];
                    ++cnt_col[j];
                }
            }
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] && (cnt_row[i]>1 || cnt_col[j]>1)){
                    ++ret;
                }
            }
        }
        return ret;
    }
};