class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        // use bitmask to represent subset
        vector<int> dp(1 << n, -1);
        for(int i = 0; i < n; ++i){
            dp[1 << i] = nums[i];
        }
        int ret = 0;
        for(int mask = 1; mask < 1 << n; ++mask){
            if(dp[mask] != -1){
                ret += dp[mask];
                continue;
            }
            int subset = (mask - 1) & mask;
            dp[mask] = dp[mask - subset] ^ dp[subset];
            ret += dp[mask];
        }
        return ret;
    }
};