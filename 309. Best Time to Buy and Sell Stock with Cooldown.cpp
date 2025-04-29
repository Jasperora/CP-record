// space-optimized state machine dp
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int hold = INT_MIN, sold = 0, can_buy = 0;
        for(auto& p : prices){
            int hold2 = hold, sold2 = sold, can_buy2 = can_buy;
            hold = max(hold2, can_buy2 - p);
            sold = hold2 + p;
            can_buy = max(can_buy2, sold2);
        }
        return max(sold, can_buy);
    }
};
// state machine dp
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> hold(n, 0), sold(n, 0), can_buy(n, 0);
        hold[0] = -prices[0];
        for(int i = 1; i < n; ++i){
            hold[i] = max(hold[i-1], can_buy[i-1] - prices[i]);
            sold[i] = hold[i-1] + prices[i];
            can_buy[i] = max(can_buy[i-1], sold[i-1]);
        }
        // sold is larger than hold
        // so don't need to consider hold
        return max(sold[n-1], can_buy[n-1]);
    }
};
// top-down state-machine dp
class Solution3 {
public:
    // status
    // 0 = hold, 1 = sold, 2 = can_buy
    unordered_map<string, int> dp;
    int dfs(const vector<int>& prices, int day, int status){
        if(day == 0){
            if(status == 0) return -prices[0];
            else return 0;
        }
        string s = to_string(day) + "-" + to_string(status);
        if(dp.count(s)) return dp[s];

        if(status == 0) return dp[s] = max(dfs(prices, day-1, 0), dfs(prices, day-1, 2) - prices[day]);
        else if(status == 1) return dp[s] = dfs(prices, day-1, 0) + prices[day];
        else return dp[s] = max(dfs(prices, day-1, 2), dfs(prices, day-1, 1));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return max(dfs(prices, n-1, 1), dfs(prices, n-1, 2));
    }
};
// different top-down state machine dp
class Solution4 {
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