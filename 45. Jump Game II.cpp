class Solution {
    public:
        int jump(vector<int>& nums) {
            int pos = 0;
            int n = nums.size();
            int ret = 0;
            while(pos < n-1){
                int mx = 0;
                int mx_idx = 0;
                for(int i = 1; i <= nums[pos]; ++i){
                    if(pos+i >= n-1){
                        ++ret;
                        return ret;
                    }
                    if(pos+i < n && i+nums[pos+i] > mx){
                        mx = i+nums[pos+i];
                        mx_idx = i;
                    }
                }
                pos += mx_idx;
                ++ret;
            }
            return ret;
        }
    };