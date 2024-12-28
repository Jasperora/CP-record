class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); ++i){
            m[nums[i]] = i+1;
        }
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i){
            if(m[target-nums[i]] && i!=m[target-nums[i]]-1){
                ans.push_back(min(i, m[target-nums[i]]-1));
                ans.push_back(max(i, m[target-nums[i]]-1));
                break;
            }
        }
        return ans;

    }
};