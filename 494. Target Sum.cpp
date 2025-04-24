// bottom-up dp
class Solution1 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto& n : nums)
            sum += n;

        // (target + sum) >> 1 will only retain the numbers with positive sign
        // it should be integer, or return 0
        if(abs(target) > sum || (target + sum) & 1) return 0;
        // so problem now is finding the number of subsets in nums whose sum is targetSubsetSum
        int targetSubsetSum = (target + sum) >> 1;
        vector<int> dp(targetSubsetSum + 1, 0);
        dp[0] = 1;
        for(auto& n : nums){
            for(int i = targetSubsetSum; i >= n; --i){
                if(dp[i - n]) dp[i] += dp[i - n];
            }
        }
        return dp[targetSubsetSum];
    }
};
// backtrack with memoization
class Solution2 {
public:
    map<pair<int, int>, int> dp;
    int backtrack(const vector<int>& nums, int target, int idx){
        if(idx == nums.size()){
            if(target == 0) return 1;
            else return 0;
        }else if(dp.count({target, idx})){
            return dp[{target, idx}];
        }else{
            dp[{target, idx}] = 0;
            dp[{target, idx}] += backtrack(nums, target - nums[idx], idx + 1);
            dp[{target, idx}] += backtrack(nums, target + nums[idx], idx + 1);
            return dp[{target, idx}];
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // target, idx
        return backtrack(nums, target, 0);
    }
};