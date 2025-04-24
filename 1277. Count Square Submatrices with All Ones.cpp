class Solution {
    public:
        int countSquares(vector<vector<int>>& matrix) {
            int m = matrix.size(), n = matrix[0].size();
            // dp[i][j]: the number of square with all ones using (i, j) as bottom right corner
            vector<vector<int>> dp(m, vector<int>(n, 0));
            
            int ret = 0;
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    if(i == 0 || j == 0) dp[i][j] = matrix[i][j];
                    else if(matrix[i][j] == 1){
                        dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                    }
                    ret += dp[i][j];
                }
            }
            return ret;
        }
    };