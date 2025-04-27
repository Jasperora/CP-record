class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        // base case: empty string
        dp[0] = true;
        for(int i = 1; i <= n; ++i){
            for(auto& word : wordDict){
                int w = word.size();
                if(i >= w && s.substr(i-w, w) == word)
                    dp[i] = dp[i] | dp[i-w];
            }
        }
        return dp[n];
    }
};