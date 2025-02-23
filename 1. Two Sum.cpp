class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> m;
            vector<int> ret;
            int n = nums.size();
            for(int i = 0; i < n; ++i){
                if(m.count(target-nums[i])){
                    ret.push_back(i);
                    ret.push_back(m[target-nums[i]]);
                    return ret;
                }else{
                    m[nums[i]] = i;
                }
            }
            return ret;
        }
    };