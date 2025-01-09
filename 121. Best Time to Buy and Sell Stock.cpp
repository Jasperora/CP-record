class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1) return 0;
        int min_so_far[prices.size()-1];
        min_so_far[0] = prices[0];
        for(int i = 1; i < prices.size()-1; ++i){
            min_so_far[i] = min(prices[i], min_so_far[i-1]);
        }
        int ret = 0, profit;
        for(int i = 1; i < prices.size(); ++i){
            profit = prices[i]-min_so_far[i-1];
            if(profit>ret) ret = profit;
        }
        return ret;
    }
};
