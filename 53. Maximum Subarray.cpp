class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], currMax = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            res += nums[i];
            if(nums[i]>res) res = nums[i];
            if(res>currMax) currMax = res;
        }
        return currMax;
    }
};