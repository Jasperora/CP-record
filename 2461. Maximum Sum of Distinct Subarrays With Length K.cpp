class Solution {
    public:
        long long maximumSubarraySum(vector<int>& nums, int k) {
            unordered_set<int> s;
            unordered_map<int, int> m;
            long long sum = 0;
            for(int i = 0; i < k; ++i){
                s.insert(nums[i]);
                m[nums[i]]++;
                sum += nums[i];
            }
            long long ma = 0;
            for(int i = 0; i+k < nums.size(); ++i){
                if(s.size()==k&&sum>ma){
                    ma = sum;
                }
                m[nums[i]]--;
                if(m[nums[i]]==0) s.erase(nums[i]);
                m[nums[i+k]]++;
                s.insert(nums[i+k]);
                sum -= nums[i];
                sum += nums[i+k];
            }
            if(s.size()==k&&sum>ma)
                ma = sum;
            return ma;
        }
    };