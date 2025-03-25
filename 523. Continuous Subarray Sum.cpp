class Solution {
    public:
        bool checkSubarraySum(vector<int>& nums, int k) {
            int curSum = 0;
            unordered_map<int, int> m;
            m[0] = -1;
            for(int i = 0; i < nums.size(); ++i){
                curSum = (curSum + nums[i]%k)%k;
                if(m.count(curSum)){
                    if(i-m[curSum]>1) return true;
                }else m[curSum] = i;
            }
            return false;
        }
    };