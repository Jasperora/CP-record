class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int left = 0;
            int ret = INT_MAX;
            int cur_sum = 0;
            for(int right = 0; right < nums.size(); ++right){
                cur_sum += nums[right];
                while(cur_sum >= target){
                    ret = min(ret, right-left+1);
                    cur_sum -= nums[left];
                    ++left;
                }
            }
    
            if(ret==INT_MAX) return 0;
            return ret;
        }
    };