class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int one_cnt = 0;
            int left = 0;
            int ret = 0;
            int cur_sum = 0;
            for(int right = 0; right < nums.size(); ++right){
                cur_sum += nums[right];
                while(right-left+1-cur_sum>k){
                    cur_sum -= nums[left];
                    ++left;
                }
                ret = max(ret, right-left+1);
            }
            return ret;
        }
    };