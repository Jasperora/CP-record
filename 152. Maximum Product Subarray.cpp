class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_dp[nums.size()+1], min_dp[nums.size()+1];
        max_dp[0] = min_dp[0] = 1;
        int ret = -11;
        for(int i = 1; i <= nums.size(); ++i){
            max_dp[i] = max(max_dp[i-1]*nums[i-1], max(min_dp[i-1]*nums[i-1], nums[i-1]));
            min_dp[i] = min(min_dp[i-1]*nums[i-1], min(max_dp[i-1]*nums[i-1], nums[i-1]));
            ret = max(max_dp[i], ret);
        }
        return ret;
    }
};
