// O(nlogn) longest increasing subsequence
class Solution1 {
    public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> stack;
        for(auto& n: nums){
            if(stack.empty() || n > stack.back())
            stack.push_back(n);
            else{
                auto iter = lower_bound(stack.begin(), stack.end(), n);
                *iter = n;
            }
        }
        return stack.size();
    }
};
// O(n^2) longest increasing subsequence
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i = n-1; i >= 0; --i){
            for(int j = i+1; j < n; ++j){
                if(nums[j] > nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int ret = 0;
        for(auto& num : dp)
            ret = max(ret, num);
        return ret;
    }
};