class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int cur_mx = 0;
        int ret = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] >= cur_mx){
                ++ret;
                cur_mx = nums[i];
            }
        }
        return ret;
    }
};