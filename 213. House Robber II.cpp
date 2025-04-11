class Solution {
    public:
        int rob_helper(const vector<int>& nums, int start, int end){
            int prev1 = 0, prev2 = 0;
            for(int i = start; i <= end; ++i){
                int tmp = max(prev1, prev2 + nums[i]);
                prev2 = prev1;
                prev1 = tmp;
            }
            return prev1;
        }
        int rob(vector<int>& nums) {
            int n = nums.size();
            if(n == 1) return nums[0];
            return max(rob_helper(nums, 0, n-2), rob_helper(nums, 1, n-1));
        }
    };