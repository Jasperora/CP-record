class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = INT_MIN;
        int n = nums.size();

        for(int i = 0; i < n; ++i)
            mx = max(mx, nums[i]);

        long long ret = 0;
        int mx_cnt = 0;
        // sliding window
        int left = 0;
        for(int right = 0; right < n; ++right){
            if(nums[right] == mx) ++mx_cnt;
            while(mx_cnt > k || (mx_cnt == k && left <= right && nums[left] != mx)){
                if(nums[left] == mx)
                    --mx_cnt;
                ++left;
            }
            if(mx_cnt == k)
                // both nums[left] and nums[right] are mx
                // left ~ right has k mx
                ret += left + 1;
        }
        return ret;
    }
};