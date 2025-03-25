class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            int sum = 0;
            unordered_map<int, int> m;
            m[0] = 1;
            int ret = 0;
            for(int i = 0; i < nums.size(); ++i){
                sum += nums[i];
                if(m.count(sum-k)){
                    ret += m[sum-k];
                }
                ++m[sum];
            }
            return ret;
        }
    };