class Solution {
public:
    vector<vector<int> > ret;
    vector<int> comb;
    void dfs(const vector<int>& c, const int& target, int idx, int sum){
        if(sum==target){
            ret.push_back(comb);
        }else if(sum>target||idx==c.size()){
            return;
        }else{
            comb.push_back(c[idx]);
            dfs(c, target, idx+1, sum+c[idx]);
            comb.pop_back();

            while(idx+1<c.size() && c[idx]==c[idx+1]){
                ++idx;
            }
            dfs(c, target, idx+1, sum);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> comb;
        dfs(candidates, target, 0, 0);
        return ret;
    }
};
