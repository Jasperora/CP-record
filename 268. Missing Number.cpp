class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = 0;
        for(int i = 0; i < nums.size(); ++i)
            missing ^= nums[i];
        for(int i = 1; i <= nums.size(); ++i)
            missing ^= i;

        return missing;
    }
};
