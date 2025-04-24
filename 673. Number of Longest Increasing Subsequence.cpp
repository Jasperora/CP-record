class Solution {
    public:
        int findNumberOfLIS(vector<int>& nums) {
            int n = nums.size();
            vector<int> dp(n, 1);
            vector<int> count(n, 1);
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < i; ++j){
                    if(nums[j] < nums[i]){
                        if(1 + dp[j] > dp[i]){
                            dp[i] = 1 + dp[j];
                            count[i] = count[j];
                        }else if(1 + dp[j] == dp[i]){
                            count[i] += count[j];
                        }
                    }
                }
            }
            int mx = *max_element(dp.begin(), dp.end());
            int ret = 0;
            for(int i = 0; i < n; ++i){
                if(dp[i] == mx)
                    ret += count[i];
            }
            return ret;
        }
    };