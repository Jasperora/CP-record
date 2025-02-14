class Solution {
private:
    vector<vector<int> > dp;
    int dfs(int i, int j, const string& s, const string& t){
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) dp[i][j] = dfs(i+1, j+1, s, t) + dfs(i+1, j, s, t);
        else dp[i][j] = dfs(i+1, j, s, t);
        return dp[i][j];
    }
public:
    int numDistinct(string s, string t) {
        int s_len = s.size();
        int t_len = t.size();
        dp.resize(s_len+1, vector<int>(t_len+1, -1));
        for(int j = 0; j < t_len+1; ++j){
            dp[s_len][j] = 0;
        }
        for(int i = 0; i < s_len+1; ++i){
            dp[i][t_len] = 1; 
        }
        // for(int i = 0; i <= s_len; ++i){
        //     for(int j = 0; j <= t_len; ++j){
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        return dfs(0, 0, s, t);
    }
};
