class Solution {
    public:
        int subarraysDivByK(vector<int>& nums, int k) {
            unordered_map<int, int> m;
            m[0] = 1;
            int curSum = 0;
            int ret = 0;
            for(int i = 0; i < nums.size(); ++i){
                curSum = (curSum + nums[i]) % k;
                if(curSum < 0) curSum += k;
                if(m.count(curSum)){
                    ret += m[curSum];
                }
                ++m[curSum];
            }
            return ret;
        }
    };