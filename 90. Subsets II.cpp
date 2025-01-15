class Solution {
public:
    vector<vector<int> > ret;
    vector<int> subset;
    void search(int idx, const vector<int>& nums){
        if(idx==nums.size()){
            ret.push_back(subset);
        }else{
            subset.push_back(nums[idx]);
            search(idx+1, nums);
            subset.pop_back();

            while(idx+1<nums.size() && nums[idx]==nums[idx+1]){
                ++idx;
            }
            search(idx+1, nums);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        search(0, nums);
        return ret;
    }
};
