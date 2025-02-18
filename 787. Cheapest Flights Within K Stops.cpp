class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            int prices[n];
            fill(prices, prices+n, 2147483647);
            prices[src] = 0;
    
            int tmp_prices[n];
            for(int i = 0; i < k+1; ++i){
                for(int j = 0; j < n; ++j) tmp_prices[j] = prices[j];
    
                for(auto& f : flights){
                    // f[0]: src, f[1]: dst, f[2]: price
                    if(prices[f[0]]==2147483647) continue;
                    if(prices[f[0]]+f[2] < tmp_prices[f[1]]){
                        tmp_prices[f[1]] = prices[f[0]] + f[2];
                    }
                }
    
                for(int j = 0; j < n; ++j) prices[j] = tmp_prices[j];
            }
            if(prices[dst]==2147483647) return -1;
            return prices[dst];
        }
    };
    