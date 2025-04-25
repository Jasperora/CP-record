#define ll long long
class Solution {
public:
    int n;
    vector<ll> dp;
    ll dfs(const vector<vector<int>>& questions, int idx){
        if(idx >= n) return 0;
        if(dp[idx] != 0) return dp[idx];
        dp[idx] = max(questions[idx][0] + dfs(questions, idx + questions[idx][1] + 1), dfs(questions, idx + 1));
        return dp[idx];
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        dp.resize(n, 0);
        ll ret = 0;
        for(int i = 0; i < n; ++i){
            ret = max(ret, dfs(questions, i));
        }
        return ret;
    }
};