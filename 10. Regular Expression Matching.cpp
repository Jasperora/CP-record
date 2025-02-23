class Solution {
    private:
        int s_len, p_len;
        vector<vector<int> > dp;
        bool dfs(int i, int j, const string& s, const string& p){
            if(dp[i][j]!=-1) return dp[i][j];
            if(i>=s_len && j>=p_len) return true;
            if(j>=p_len) return false;
            
            bool match = i < s_len && (s[i]==p[j] || p[j]=='.');
    
            if(j+1<p_len && p[j+1]=='*'){
                // dfs(i, j+2): not use *
                // dfs(i+1, j): use * once
                dp[i][j] = dfs(i, j+2, s, p) || (match && dfs(i+1, j, s, p));
                return dp[i][j];
            }
            if(match) {
                dp[i][j] = dfs(i+1, j+1, s, p);
                return dp[i][j];
            }
            return false;
        }
    public:
        bool isMatch(string s, string p) {
            s_len = s.size();
            p_len = p.size();
            dp.assign(s_len+1, vector<int>(p_len+1, -1));
            return dfs(0, 0, s, p);
        }
    };
    