class Solution {
public:
    map<pair<int, int>, int> m;
    int dfs(int i, int sum, vector<int>& nums, int& target){
        if(m.count({i, sum})) return m[{i, sum}];
        else{
            if(i==nums.size()){
                if(sum==target) m[{i, sum}] = 1;
                else m[{i, sum}] = 0;
            }
            else m[{i, sum}] = dfs(i+1, sum+nums[i], nums, target) + dfs(i+1, sum-nums[i], nums, target);
        }
        return m[{i, sum}];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(0, 0, nums, target);
    }
};
