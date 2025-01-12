class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[nums.size()];
        fill(dp, dp+nums.size(), 1);
        for(int i = 1; i < nums.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i]>nums[j])
                    dp[i] = max(dp[i], 1+dp[j]);
            }
        }
        int ret = 0;
        for(auto& n : dp){
            if(n>ret) ret = n;
        }
        return ret;
    }
};