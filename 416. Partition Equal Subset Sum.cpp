class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int sum = 0;
            for(auto& n : nums)
                sum += n;
            if(sum & 1) return false;
            int target = sum >> 1;
            vector<bool> dp(target + 1, false);
            dp[0] = true;
            for(auto& n : nums){
                // because of bounded
                // if i = n ~ target, n could be used several times
                // i = target ~ n can avoid this problem
                for(int i = target; i >= n; --i){
                    if(dp[i - n]) dp[i] = true;
                }
            }
            return dp[target];
        }
    };