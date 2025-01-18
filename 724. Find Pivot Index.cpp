class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(auto& n : nums) sum += n;
        int tmp = 0;
        for(int i = 0; i < nums.size(); ++i){
            if((tmp==(sum-nums[i])>>1)&&!((sum-nums[i])&1)){
                return i;}
            tmp += nums[i];
        }
        return -1;
    }
};