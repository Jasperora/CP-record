class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool row_zero = false, col_zero = false;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(!matrix[i][j]){
                    if(!i) row_zero |= 1;
                    if(!j) col_zero |= 1;
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if(!matrix[0][j]||!matrix[i][0])
                    matrix[i][j] = 0;
            }
        }
        if(row_zero)
            for(int i = 0; i < n; ++i)
                matrix[0][i] = 0;
        if(col_zero)
            for(int i = 0; i < m; ++i)
                matrix[i][0] = 0;
    }
};
