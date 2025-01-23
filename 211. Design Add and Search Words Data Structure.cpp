class Solution {
public:
    map<pair<int, int>, int> dp;
    int dfs(int i, bool buying, vector<int>& prices){
        if(i>=prices.size()) return 0;
        if(dp.count({i, buying})) return dp[{i, buying}];

        int cooldown = dfs(i+1, buying, prices);
        if(buying){
            int buy = dfs(i+1, false, prices) - prices[i];
            dp[{i, buying}] = max(buy, cooldown);
        }else{
            int sell = dfs(i+2, true, prices) + prices[i];
            dp[{i, buying}] = max(sell, cooldown);
        }
        return dp[{i, buying}];
    }
    int maxProfit(vector<int>& prices) {
        return dfs(0, true, prices);
    }
};
