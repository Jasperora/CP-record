class Solution {
public:
    vector<vector<int> > ret;
    void dfs(int idx, int sum, vector<int> comb, const vector<int>& nums, const int& target){
        if(sum==target){
            ret.push_back(comb);
        }else if(sum>target||idx==nums.size()){
            return;
        }else{
            comb.push_back(nums[idx]);
            dfs(idx, sum+nums[idx], comb, nums, target);
            comb.pop_back();
            dfs(idx+1, sum, comb, nums, target);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> comb;
        dfs(0, 0, comb, nums, target);
        return ret;
    }
};
