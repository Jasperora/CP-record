class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            if(obstacleGrid[0][0]) return 0;
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
            vector<int> dp(n, 0);
            dp[0] = 1;
            for(int i = 1; i < n; ++i){
                if(!obstacleGrid[0][i]) dp[i] = dp[i-1];
            }
            for(int i = 1; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    if(obstacleGrid[i][j]) dp[j] = 0;
                    else if(j >= 1) dp[j] += dp[j-1];
                }
            }
            return dp[n-1];
        }
    };