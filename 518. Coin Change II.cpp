class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount+1];
        fill(dp, dp+amount+1, 0);
        dp[0] = 1;
        int n = coins.size();
        long long tmp;
        for(int i = 0; i < n; ++i){
            for(int j = coins[i]; j <= amount; ++j){
                tmp = (long long)dp[j] + (long long)dp[j-coins[i]];
                if(tmp>2147483647) dp[j] = 2147483647;
                else dp[j] += dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};
