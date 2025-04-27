// bottom-up dp
class Solution1 {
public:                  
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
        if(l1 + l2 != l3) return false;
        vector<vector<bool>> dp(l1+1, vector<bool>(l2+1, false));
        // both s1 and s2 are empty
        dp[l1][l2] = true;

        for(int i = l1; i >= 0; --i){
            for(int j = l2; j >= 0; --j){
                if(i < l1 && s1[i] == s3[i+j] && dp[i+1][j])
                    dp[i][j] = true;
                if(j < l2 && s2[j] == s3[i+j] && dp[i][j+1])
                    dp[i][j] = true;
            }
        }
        return dp[0][0];
    }
};
// dfs + memoization
class Solution2 {
public:
    int l1, l2, l3;
    unordered_map<string, bool> dp;
    bool dfs(const string& s1, const string& s2, const string& s3, int i, int j){
        string st = "";
        st = to_string(i) + "," + to_string(j);
        // empty string and empty string can from empty string
        if(i >= l1 && j >= l2)
            return dp[st] = true;
        if(dp.count(st))
            return dp[st];
        if(i < l1 && s1[i] == s3[i+j] && dfs(s1, s2, s3, i+1, j))
            return true;
        if(j < l2 && s2[j] == s3[i+j] && dfs(s1, s2, s3, i, j+1))
            return true;
        return dp[st] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        l1 = s1.size();
        l2 = s2.size();
        l3 = s3.size();
        if(l1 + l2 != l3) return false;
        return dfs(s1, s2, s3, 0, 0);
    }
};