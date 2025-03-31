class Solution {
    public:
        int maxSubarraySumCircular(vector<int>& nums) {
            int maxsubsum = INT_MIN;
            int minsubsum = INT_MAX;
            int cur_max_sum = 0;
            int cur_min_sum = 0;
            int total_sum = 0;
            for(int i = 0; i < nums.size(); ++i){
                total_sum += nums[i];
                cur_max_sum = max(cur_max_sum + nums[i], nums[i]);
                cur_min_sum = min(cur_min_sum + nums[i], nums[i]);
                
                maxsubsum = max(maxsubsum, cur_max_sum);
                minsubsum = min(minsubsum, cur_min_sum);
            }
            if(minsubsum==total_sum) return maxsubsum;
            return max(total_sum-minsubsum, maxsubsum);
        }
    };