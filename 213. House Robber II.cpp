class Solution {
public:
    int rob(vector<int>& nums) {
        int m = 0;
        if(nums.size()<=2){
            for(auto& n : nums)
                m = max(m, n);
            return m;
        }
        int dp_steal_1[nums.size()-1];
        dp_steal_1[0] = nums[0];
        dp_steal_1[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size()-1; ++i){
            dp_steal_1[i] = max(dp_steal_1[i-1], dp_steal_1[i-2]+nums[i]);
        }
        int dp_not_steal_1[nums.size()];
        dp_not_steal_1[0] = 0;
        dp_not_steal_1[1] = nums[1];
        for(int i = 2; i < nums.size(); ++i){
            dp_not_steal_1[i] = max(dp_not_steal_1[i-1], dp_not_steal_1[i-2]+nums[i]);
        }
        return max(dp_steal_1[nums.size()-2], dp_not_steal_1[nums.size()-1]);
    }
};
