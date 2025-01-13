class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto& n : nums) sum += n;
        if(sum&1) return false;
        int target = sum>>1;
        bool dp[target+1];
        for(int i = 1; i <= target; ++i) dp[i] = false;
        dp[0] = true;
        for(auto& n : nums){
            for(int i = target; i >= n; --i){
                if(dp[i-n]) dp[i] = true;
            }
        }
        return dp[target];
    }
};
