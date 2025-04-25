class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long ret = LLONG_MIN;
            int n = nums.size();
            for(int i = 0; i < n-2; ++i){
                for(int j = i+1; j < n-1; ++j){
                    for(int k = j+1; k < n; ++k){
                        ret = max(ret, ((long long)nums[i]-(long long)nums[j])*(long long)nums[k]);
                    }
                }
            }
            return ret < 0 ? 0 : ret;
        }
    };