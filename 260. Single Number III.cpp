class Solution {
    public:
        vector<int> singleNumber(vector<int>& nums) {
            int x = nums[0];
            for(int i = 1; i < nums.size(); ++i){
                x ^= nums[i];
            }
            int a = 0, b = 0;
            for(int i = 0; i < 32; ++i){
                if(x&(1<<i)){
                    for(int j = 0; j < nums.size(); ++j){
                        if(nums[j]&(1<<i)){
                            a ^= nums[j];
                        }else{
                            b ^= nums[j];
                        }
                    }
                    break;
                }
            }
            return {a, b};
        }
    };