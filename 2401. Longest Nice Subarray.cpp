class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            if(nums.size()==1) return 1;
            int ret = 1;
            for(int i = 0; i < nums.size()-1; ++i){
                int n = nums[i];
                int tmp;
                for(int j = i+1; j < nums.size(); ++j){
                    if(!(n&nums[j])){
                        tmp = j-i+1;
                        n |= nums[j];
                    }else{
                        break;
                    }
                }
                ret = max(ret, tmp);
            }
            return ret;
        }
    };