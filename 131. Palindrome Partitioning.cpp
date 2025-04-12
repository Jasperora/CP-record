class Solution {
    public:
        vector<vector<string>> ret;
        vector<string> cur;
        vector<vector<bool>> dp;
        int n;
        void backtrack(const string& s, int start){
            if(start == n){
                ret.push_back(cur);
            }else{
                for(int i = start; i < n; ++i){
                    if(dp[start][i]){
                        cur.push_back(s.substr(start, i - start + 1));
                        backtrack(s, i + 1);
                        cur.pop_back();
                    }
                }
            }
        }
        vector<vector<string>> partition(string s) {
            n = s.size();
            dp.resize(n, vector<bool>(n, false));
            for(int i = 0; i < n; ++i)
                dp[i][i] = true;
            for(int i = 0; i < n-1; ++i)
                dp[i][i+1] = s[i] == s[i+1];
            for(int len = 2; len < n; ++len){
                for(int i = 0; i + len < n; ++i){
                    dp[i][i+len] = dp[i+1][i+len-1] && s[i] == s[i+len];
                }
            }
            backtrack(s, 0);
            return ret;
        }
    };