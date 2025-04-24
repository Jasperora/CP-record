class Solution {
    public:
        int lastStoneWeightII(vector<int>& stones) {
            // partition stones to two sets
            // want to minimize the difference of weight sum between two sets
            // because each time one set loses some weight, another loses the same weight
            int sum = 0;
            for(auto& stone : stones)
                sum += stone;
            // want to find a subset of stones
            // whose weight sum is as close as possible to target
            int target = sum >> 1;
            vector<bool> dp(target + 1, false);
            dp[0] = true;
            for(auto& stone : stones){
                // bounded
                for(int i = target; i - stone >= 0; --i){
                    if(dp[i - stone]) dp[i] = true;
                }
            }
            for(int i = target; i >= 0; --i){
                // two groups: i, sum - i
                // so last stone weight would be sum - 2*i
                if(dp[i]) return sum - 2*i;
            }
            return 0;
        }
    };