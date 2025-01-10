class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i){
            int M = 10001;
            for(auto& c : coins){
                if(c<=i){
                    if(dp[i-c]==-1)
                        continue;
                    M = min(M, dp[i-c]+1);
                }
            }
            if(M==10001)
                dp[i] = -1;
            else
                dp[i] = M;
        }
        return dp[amount];
    }
};
