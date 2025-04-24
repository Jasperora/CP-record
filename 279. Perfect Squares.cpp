class Solution {
    public:
        int numSquares(int n) {
            int upper_limit = floor(sqrt(n));
            vector<int> dp(n + 1, 0);
            for(int i = 1; i <= n; ++i){
                int M = INT_MAX;
                for(int j = 1; j <= upper_limit; ++j){
                    if(j*j <= i)
                        M = min(M, dp[i - j*j]);
                }
                dp[i] = M + 1;
            }
            return dp[n];
        }
    };